#pragma once
#include "Customer.h"

class Bill {
private:
	Customer customer;
	int amount, price, total;
public:
	void setCustomer(string, string, int, int, int);
	friend ostream& operator<<(ostream& os, Bill);

};
