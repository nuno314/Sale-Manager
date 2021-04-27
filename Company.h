#pragma once
#include "Customer.h"

class Company : public Customer {
private:
	int EmployeesAmount;
public:
	void setEmployeesAmount(int);
	int getEmployeesAmount();
	float discount();
};