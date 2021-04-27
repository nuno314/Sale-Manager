#include "PrivateCustomer.h"

void PrivateCustomer::setDistance(float _distance) {
	Distance = _distance;
}

float PrivateCustomer::getDistance() {
	return Distance;
}

float PrivateCustomer::discount(int amount, int price) {
	if (amount < 7)
		return 0;

	float discount = 0.05;

	if (Distance < 10) {
		discount += (float)10000 / price;
	}

	return discount;
}