#pragma once
#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
	string ID, Name;
public:
	Customer();
	~Customer();
	void setID(string);
	void setName(string);
	string getID();
	string getName();

};