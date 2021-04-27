#include "Tier1Agent.h"

void Tier1Agent::setCoopTime(int _time) {
	CoopTime = _time;
}

int Tier1Agent::getCoopTime() {
	return CoopTime;
}

float Tier1Agent::discount() {
	float discount = 0.3;

	if (CoopTime > 3) {
		
		if (CoopTime > 7) {
			discount = 0.35;
		}
		else
		{
			discount += (CoopTime - 3) * 0.01;
		}
	}

	return discount;
}