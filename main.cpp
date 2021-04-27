#include "Manage.h"

Manage ABC;

void load() {
	ABC.loadCustomer();
	ABC.loadOrder();
	
	ABC.billCalculation();
	ABC.importBill();
	//ABC.importOrder();
}

int main() {
	load();
};
