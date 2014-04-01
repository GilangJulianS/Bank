#include "Event.h"
#include <assert.h>
#include <string>

using namespace std;

int main(){
	int pil, temp1;
	char* in = new char[100];
	Event ev;
	cout << "*********** Driver kelas Event ************" << endl;
	cout << "Silahkan pilih menu dibawah ini :" << endl;
	cout << "1. setNewEvent"<< endl;
	cout << "2. getDateTime"<< endl;
	cout << "3. getType"<< endl;
	cout << "4. getDepartId" << endl;
	cout << "Pilihan anda : ";
	cin >> pil;
	while(pil != 9){
		if (pil == 1){
			cin.getline(in,100);
			cin.getline(in,100);
			ev.setNewEvent(in);
		}
		else if(pil == 2){
			cout << ev.getDateTime() << endl;
		}
		else if(pil == 3){
			if(ev.getType() == 0){
				cout << "Event Departure" << endl;
			}
			else if(ev.getType() == 1){
				cout << "Event Arrival" << endl;
			}
		}
		else if(pil == 4){
			cout << "Id yang melakukan Departure :" << ev.getDepartId() << endl;
		}
		cout << "*********** Driver kelas Event ************" << endl;
		cout << "Silahkan pilih menu dibawah ini :" << endl;
		cout << "1. setNewEvent"<< endl;
		cout << "2. getDateTime"<< endl;
		cout << "3. getType"<< endl;
		cout << "4. getDepartId" << endl;
		cout << "Pilihan anda : ";
		cin >> pil;
	}
return 0;
}

void changeDate(DateTime *d1){
	int d,m,y,h,mnt,s;
	cout << "Tanggal sebelumnya :" << (*d1) << endl;
	cout << "Masukkan tanggal yang baru :";
	cin >> d;
	cout << "Masukkan bulan yang baru :";
	cin >> m;
	cout << "Masukkan tahun yang baru :";
	cin >> y;
	cout << "Masukkan jam yang baru :";
	cin >> h;
	cout << "Masukkan menit yang baru :";
	cin >> mnt;
	cout << "Masukkan detik yang baru :";
	cin >> s;
	(*d1).setDateTime(d,m,y,h,mnt,s);
	cout << "tanggal setelah diganti :" << (*d1) << endl;
}

void printOne(DateTime d1){
	int temp1;
	cout << "Masukkan yang ingin dilihat :" << endl;
	cout << "1. Date" << endl;
	cout << "2. Time" << endl;
	cout << "Pilihan anda :";
	cin >> temp1;
	assert(temp1 > 0 && temp1 < 3);
	if (temp1 == 1){
		cout << d1.getDate() << endl;
	}
	else{
		cout << d1.getTime() << endl;
	}
	cout << endl;
}