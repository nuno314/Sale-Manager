#pragma once
#include "Customer.h"
class PrivateCustomer : public Customer {
private:
	float Distance;
public:
	void setDistance(float);
	float getDistance();
	float discount(int, int);
};