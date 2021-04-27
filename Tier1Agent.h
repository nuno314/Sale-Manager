#pragma once
#include "Customer.h"


class Tier1Agent : public Customer {
private:
	int CoopTime;
public:
	void setCoopTime(int);
	int getCoopTime();
	float discount();
};