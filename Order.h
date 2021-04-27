#pragma once
#include "Company.h"
#include "Customer.h"
#include "PrivateCustomer.h"
#include "Tier1Agent.h"

class Order {
private:
	Customer customer;
	int amount, price;
public:
	void setOrder(string, string, int, int);
	Customer getCustomer();
	int getAmount();
	int getPrice();
};