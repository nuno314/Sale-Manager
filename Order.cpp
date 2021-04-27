#include "Order.h"

void Order::setOrder(string _ID, string _name, int _amount, int _price) {
	customer.setID(_ID);
	customer.setName(_name);
	amount = _amount;
	price = _price;
}

Customer Order::getCustomer() {
	return customer;
}

int Order::getAmount() {
	return amount;
}

int Order::getPrice() {
	return price;
}