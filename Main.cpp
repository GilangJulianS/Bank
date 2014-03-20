#include "Queue.h"

using namespace std;

int main(){
	int a, n;
	Queue* q;
	q = new Queue(5);
	cout << "1. Add" << endl;
	cout << "2. Delete" << endl;
	cout << "3. NBElmt" << endl;
	cout << "4. DeleteLast" << endl;
	cout << "9. Exit" << endl;
	cin >> n;
	while(n != 9){
		if(n == 1){
			cout << "Masukkan angka yang ingin anda masukkan :";
			cin >> a;
			(*q).Add(a);
			cout << (*q);
			cout << endl;
		}
		else if(n == 2){
			cout << "element yang di delete : "<< (*q).Delete() << endl;
			cout << (*q);
		}
		else if(n == 3){
			cout << "Jumlah element pada queue :"<< (*q).NBElmt() << endl;
			cout << (*q);
		}
		else if(n == 4){
			cout << "element yang di delete : " << (*q).DeleteLast() << endl;
		}
		cout << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. NBElmt" << endl;
		cout << "4. DeleteLast" << endl;
		cout << "9. Exit" << endl;
		cin >> n;
	}
return 0;
}