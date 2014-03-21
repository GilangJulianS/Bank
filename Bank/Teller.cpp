#include "Teller.h"


int Teller::lastTellerId = 0;

Teller::Teller(){
	customers = new Queue();
	nCustomers = 0;
	serving = false;
	id = lastTellerId;
	lastTellerId++;
}

Teller::Teller(const Teller& T){
	if(customers != NULL)
		delete customers;
	customers = new Queue();
	customers = T.customers;
	nCustomers = T.nCustomers;
	serving = T.serving;
}

Teller& Teller::operator=(const Teller& T){
	if(customers != NULL)
		delete customers;
	customers = new Queue();
	customers = T.customers;
	nCustomers = T.nCustomers;
	serving = T.serving;
	return *this;
}

ostream& operator<<(ostream& os, const Teller& T){
	os << "Q{" << T.id << "} = " << *(T.customers) << endl;
	return os;
}

Teller::~Teller(){
	delete customers;
}

void Teller::addCustomer(int customerId){
	customers->Add(customerId);
	nCustomers++;
	if(nCustomers > 0)
		serving = true;
	else
		serving = false;
}

void Teller::processCustomer(){
	customers->Delete();
	nCustomers--;
	if(nCustomers > 0)
		serving = true;
	else
		serving = false;
}

int Teller::getFrontCustomerId(){
	Queue* temp = new Queue();
	*temp = *customers;
	return temp->Delete();
}

int Teller::getCustomerCount(){
	return nCustomers;
}

bool Teller::isServing(){
	return serving;
}