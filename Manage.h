#pragma once
#include "Customer.h"
#include "PrivateCustomer.h"
#include "Tier1Agent.h"
#include "Company.h"
#include "Bill.h"
#include "Order.h"
#include <vector>
#include <fstream>

class Manage {
private:
	vector<PrivateCustomer> PrivateCustomerList;
	vector<Tier1Agent> Tier1AgentList;
	vector<Company> CompanyList;
	vector<Bill> BillList;
	vector<Order> OrderList;
public:
	Manage();
	void loadCustomer();
	void loadOrder();
	float discount(string, int, int);
	float discount(string);
	void billCalculation();
	void importBill();
	void importOrder();

};