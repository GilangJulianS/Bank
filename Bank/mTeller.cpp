#include "Teller.h"

using namespace std;

int main(){
	int temp, n;
	Teller t;
	cout << "1. Add Customer" << endl;
	cout << "2. Process Customer" << endl;
	cout << "3. Jokey(pindah barisan)" << endl;
	cout << "4. getFrontCustomerID" << endl;
	cout << "5. getCustomerCount" << endl;
	cout << "6. Jokey ID" << endl;
	cout << "7. Apakah teller sedang melayani" << endl;
	cout << "9. Exit" << endl;
	cin >> n;
	while(n != 9){
		if(n == 1){
			cout << "Masukkan ID yang ingin anda masukkan :";
			cin >> temp;
			t.addCustomer(temp);
			cout << t << endl;
		}
		else if(n == 2){
			t.processCustomer();
			cout << t << endl;
		}
		else if(n == 3){
			cout << "Masukkan ID yang ingin jokey :";
			cin >> temp;
			t.jockey(temp);
			cout << t << endl;
		}
		else if(n == 4){
			cout << t.getFrontCustomerId() << endl;
		}
		else if(n == 5){
			cout << t.getCustomerCount() << endl;
		}
		else if(n == 6){
			cout << t.jockey() << endl;
		}
		else if(n = 7){
			if(t.isServing()){
				cout << "Teller sedang melayani" << endl;
			}
			else{
				cout << "Teller tidak sedang melayani" << endl;
			}
		}
		cout << "1. Add Customer" << endl;
		cout << "2. Process Customer" << endl;
		cout << "3. Jokey(pindah barisan)" << endl;
		cout << "4. getFrontCustomerID" << endl;
		cout << "5. getCustomerCount" << endl;
		cout << "6. Jokey ID" << endl;
		cout << "7. Apakah teller sedang melayani" << endl;
		cout << "9. Exit" << endl;
		cin >> n;
	}
return 0;
}