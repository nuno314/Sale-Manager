#include "Company.h"

void Company::setEmployeesAmount(int _amount) {
	EmployeesAmount = _amount;
}

int Company::getEmployeesAmount() {
	return EmployeesAmount;
}

float Company::discount() {
	if (EmployeesAmount > 100)
		return 0.03; // 3%

	if (EmployeesAmount > 500)
		return 0.05;
	
	return 0;
}