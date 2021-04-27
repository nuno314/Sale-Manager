#include "Bill.h"

void Bill::setCustomer(string _ID, string _name, int _amount, int _price, int _total) {
	customer.setID(_ID);
	customer.setName(_name);
	amount = _amount;
	price = _price;
	total = _total;
}

ostream& operator<<(ostream& os, Bill bill) {
	os << bill.customer.getID() << endl;
	os << bill.customer.getName() << endl;
	os << bill.price << endl;
	os << bill.amount << endl;
	os << bill.total << endl;
	return os;
}