#include "Manage.h"

Manage::Manage() {
	
}

void Manage::loadCustomer() {
	string line;
	ifstream info("CustomerInfo.txt");
	if (!info) {
		cout << "Open file failed..." << endl;
		return;
	}

	string check, _ID, _name;
	int _lastInfo;
	getline(info, check);

	while (check != "END") {
		_ID = check;
		getline(info, _name);
		info >> _lastInfo;

		if (_ID.substr(0, 3) == "PRV") {
			PrivateCustomer _customer;
			_customer.setID(_ID);
			_customer.setName(_name);
			_customer.setDistance(_lastInfo);
			PrivateCustomerList.push_back(_customer);
		}
		else if (_ID.substr(0, 3) == "AGT") {
			Tier1Agent _agent;
			_agent.setID(_ID);
			_agent.setName(_name);
			_agent.setCoopTime(_lastInfo);
			Tier1AgentList.push_back(_agent);
		}
		else if (_ID.substr(0, 3) == "CPN") {
			Company _company;
			_company.setID(_ID);
			_company.setName(_name);
			_company.setEmployeesAmount(_lastInfo);
			CompanyList.push_back(_company);
		}

		while (getline(info, check)) {
			if (!check.empty()) {
				break;
			}
		}
	}
}

void Manage::loadOrder() {
	string line;
	ifstream order("Order.txt");
	if (!order) {
		cout << "Open file failed..." << endl;
		return;
	}

	string check, _ID, _name;
	int _amount, _price;
	getline(order, check);

	while (check != "END") {
		Order _order;
		_ID = check;
		getline(order, _name);
		order >> _amount >> _price;
		_order.setOrder(_ID, _name, _amount, _price);
		OrderList.push_back(_order);
		
		while (getline(order, check)) {
			if (!check.empty()) {
				break;
			}
		}
	}
}

float Manage::discount(string _ID, int _amount, int _price) {
	float discount = 0;
	if (_ID == "PRV") { // Private Customer
		for (int i = 0; i < PrivateCustomerList.size(); i++) {
			if (_ID == PrivateCustomerList[i].getID()) {
				discount = PrivateCustomerList[i].discount(_amount, _price);
			}
		}
	}
	return discount;
}

float Manage::discount(string _ID) {
	float discount = 0;

	if (_ID == "AGT") { // Agent
		for (int i = 0; i < Tier1AgentList.size(); i++) {
			if (_ID == Tier1AgentList[i].getID()) {
				discount = Tier1AgentList[i].discount();
			}
		}
	}
	else if (_ID == "CPN") {
		for (int i = 0; i < CompanyList.size(); i++) {
			if (_ID == CompanyList[i].getID()) {
				discount = CompanyList[i].discount();
			}
		}
	}
	return discount;
}

void Manage::billCalculation() {


	for (int i = 0; i < OrderList.size(); i++) {
		Order currOrd = OrderList[i];
		
		string _ID = currOrd.getCustomer().getID();
		string _name = currOrd.getCustomer().getName();
		
		int _amount = currOrd.getAmount();
		int _price = currOrd.getPrice();
		int total = 0;
		cout << _ID << " " << _amount << " " << _price << " ";
		if (_ID.substr(0,3) == "PRV") {
			cout << "1" << endl;
			for (int i = 0; i < PrivateCustomerList.size(); i++) {
				if (_ID == PrivateCustomerList[i].getID()) {
					PrivateCustomer currCtm = PrivateCustomerList[i];
					total =( _amount * _price * (1 - currCtm.discount(_amount, _price)))*1.1;
					cout << total << endl;
				}
			}
		}
		else if (_ID.substr(0,3) == "AGT") {
			for (int i = 0; i < Tier1AgentList.size(); i++) {
				if (_ID == Tier1AgentList[i].getID()) {
					Tier1Agent currAgt = Tier1AgentList[i];
					total = (_amount * _price * (1 - currAgt.discount())) * 1.1;
					cout << total << endl;
				}
			}
		}
		else if (_ID.substr(0,3) == "CPN") {
			for (int i = 0; i < CompanyList.size(); i++) {
				if (_ID == CompanyList[i].getID()) {
					Company currCpn = CompanyList[i];
					total = (_amount * _price * (1 - currCpn.discount())) * 1.1;
					cout << total << endl;
				}
			}
		}
		Bill bill;
		bill.setCustomer(_ID, _name, _amount, _price, total);
		BillList.push_back(bill);
	}
}

void Manage::importBill(){
	ofstream os("BillImport.txt");
	for (int i = 0; i < BillList.size(); i++) {
		os << BillList[i] << endl;
		
	}
}

void Manage::importOrder() {
	ofstream os("OrderImport.txt");
	for (int i = 0; i < OrderList.size(); i++) {
		cout << OrderList[i].getCustomer().getID() << endl;
		cout << OrderList[i].getCustomer().getName() << endl;
		cout << OrderList[i].getAmount() << endl;
		cout << OrderList[i].getPrice() << endl;

	}
}