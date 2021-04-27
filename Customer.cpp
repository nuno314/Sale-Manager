#include "Customer.h"

Customer::Customer() {
	ID = "";
	Name = "";
}

Customer::~Customer() {
	ID = "";
	Name = "";
}

void Customer::setID(string _ID) {
	ID = _ID;
}

void Customer::setName(string _Name) {
	Name = _Name;
}

string Customer::getID() {
	return ID;
}

string Customer::getName() {
	return Name;
}