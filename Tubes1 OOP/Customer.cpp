#include <iostream>
#include "Customer.h"

int Customer::lastId = 0;

Customer::Customer(){
	Customer::lastId++;
	id = Customer::lastId;
}

Customer::~Customer(){}