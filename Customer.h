#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
public:
	Customer(){}
	int getId(){return Id;}
	void setId(int id){Id = id;}
private :
	int Id;
};

#endif