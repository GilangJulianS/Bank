class Customer{

public:
	Customer();
	Customer(const Customer&);
	Customer& operator=(const Customer& customer);
	~Customer();


private:
	int id;
	static int lastId;
};