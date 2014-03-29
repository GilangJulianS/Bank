#include "Queue.h"

class Teller{
public:
	Teller();
	Teller(const Teller&);
	Teller& operator=(const Teller&);
	friend ostream& operator<<(ostream&, const Teller&);
	~Teller();

	void addCustomer(int customerId);
	void processCustomer();
	void jockey(int customerId);
	int getFrontCustomerId();
	int getCustomerCount();
	int jockey();
	bool isServing();
private:
	static int lastTellerId;
	Queue* customers;
	int nCustomers;
	int id;
	bool serving;
};