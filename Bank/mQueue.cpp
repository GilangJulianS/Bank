#include "Queue.h"

using namespace std;

int main(){
	int a, n;
	Queue<int>* q;
	q = new Queue<int>(5);
	cout << "1. Add" << endl;
	cout << "2. Delete" << endl;
	cout << "3. NBElmt" << endl;
	cout << "4. DeleteLast" << endl;
	cout << "5. Copy Queue" << endl;
	cout << "6. Cek Queue Penuh atau tidak" << endl;
	cout << "9. Exit" << endl;
	cin >> n;
	while(n != 9){
		if(n == 1){
			cout << "Masukkan angka yang ingin anda masukkan :";
			cin >> a;
			(*q).Add(a);
			//cout << (*q);
		}
		else if(n == 2){
			cout << "element yang di delete : "<< (*q).Delete() << endl;
			//cout << (*q);
		}
		else if(n == 3){
			cout << "Jumlah element pada queue :"<< (*q).NBElmt() << endl;
			//cout << (*q);
		}
		else if(n == 4){
			cout << "element yang di delete : " << (*q).DeleteLast() << endl;
			//cout << (*q);
		}
		else if(n == 5){
			Queue<int>* q2 = q;
			//cout << "Queue 1 : " << (*q);
			//cout << "Queue 2 : " << (*q2);
		}
		else if(n == 6){
			if((*q).isFull()){
				cout << "Antrian penuh" << endl;
			}
			else{
				cout << "Antrian tidak penuh" << endl;
			}
			if((*q).isEmpty()){
				cout << "Antrian Kosong" << endl;
			}
			else{
				cout << "Antrian tidak kosong" << endl;
			}
		}
		cout << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. NBElmt" << endl;
		cout << "4. DeleteLast" << endl;
		cout << "5. Copy Queue" << endl;
		cout << "6. Cek Queue Penuh atau tidak" << endl;
		cout << "9. Exit" << endl;
		cin >> n;
	}
return 0;
}