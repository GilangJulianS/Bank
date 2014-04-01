#include "Teller.h"


int Teller::lastTellerId = 0;


/** @name Lima Sekawan
 */
///@{
/**  Konstruktor dari kelas Teller*/
Teller::Teller(){
	customers = new Queue();
	nCustomers = 0;
	serving = false;
	id = lastTellerId;
	lastTellerId++;
}
/**  COpy Konstruktor dari kelas Teller*/
Teller::Teller(const Teller& T){
	if(customers != NULL)
		delete customers;
	customers = new Queue();
	customers = T.customers;
	nCustomers = T.nCustomers;
	serving = T.serving;
}
/**  Operator = dari kelas Teller*/
Teller& Teller::operator=(const Teller& T){
	if(customers != NULL)
		delete customers;
	customers = new Queue();
	customers = T.customers;
	nCustomers = T.nCustomers;
	serving = T.serving;
	return *this;
}
/**  Fungsi untuk print(outputstream) kelas Teller*/
ostream& operator<<(ostream& os, const Teller& T){
	os << "Q{" << T.id << "} = " << *(T.customers) << endl;
	return os;
}
/**  Destruktor dari kelas Teller*/
Teller::~Teller(){
	delete customers;
}
///@}

/**  Prosedur untuk menambahkan customer kedalam Teller*/
void Teller::addCustomer(int customerId){
	customers->Add(customerId);
	nCustomers++;
	if(nCustomers > 0)
		serving = true;
	else
		serving = false;
}

/**  Prosedur untuk menghilangkan satu customer terdepan pada Teller*/
void Teller::processCustomer(){
	customers->Delete();
	nCustomers--;
	if(nCustomers > 0)
		serving = true;
	else
		serving = false;
}
/**  Fungsi yang mengembalikan customer id dari customer yang melakukan Jokeying*/
int Teller::jockey(){
	nCustomers--;
	return customers->DeleteLast();
}
/**  Prosedur untuk jokeying, dimana customer dengan customer id tertentu berpindah kedalam teller ini*/
void Teller::jockey(int customerId){
	nCustomers++;
	if(nCustomers > 0)
		serving = true;
	else
		serving = false;
	customers->Add(customerId);
}

/** @name Lima Sekawan
 */
///@{
/** Fungsi yang mengembalikan customer id dari customer yang menempati barisan terdepan dari Teller tersebut */
int Teller::getFrontCustomerId(){
	Queue* temp = new Queue();
	*temp = *customers;
	return temp->Delete();

}
/** Mengembalikan jumlah customer yang sedang mengantri di Teller */
int Teller::getCustomerCount(){
	return nCustomers;
}
/** Mengembalikan nilai true jika Teller tidak kosong */
bool Teller::isServing(){
	return serving;
}
///@}