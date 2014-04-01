#include "Date.h"
#include <assert.h>

using namespace std;

void printOne(Date d1);
void gantiOne(Date *d1);
void changeDate(Date *d1);

int main(){
	int pil, temp1, temp2, temp3;
	Date* d1;
	Date d2;
	cout << "*********** Driver kelas Date ************" << endl;
	cout << "Silahkan pilih menu dibawah ini :" << endl;
	cout << "1. Konstruktor dengan parameter untuk Date 1"<< endl;
	cout << "2. Print Date"<< endl;
	cout << "3. Print salah satu tanggal (tanggal, bulan, tahun)"<< endl;
	cout << "4. Ganti nilai tanggal/bulan/tahun"<< endl;
	cout << "5. Ganti tanggal keseluruhan" << endl;
	cout << "6. Bandingkan Tanggal"<< endl;
	cout << "Pilihan anda : ";
	cin >> pil;
	while(pil != 9){
		if (pil == 1){
			cout << "Masukkan tanggal :";
			cin >> temp1;
			cout << "Masukkan bulan :";
			cin >> temp2;
			cout << "Masukkan tahun :";
			cin >> temp3;
			d1 = new Date(temp1, temp2, temp3);	
			
		}
		else if(pil == 2){
			cout << "Masukkan Date yang ingin dilihat(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				cout << *d1 << endl;
			}
			else{
				cout << d2 << endl;
			}
			cout << endl;
		}
		else if(pil == 3){
			cout << "Masukkan Date yang ingin dilihat(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				printOne(*d1);
			}
			else{
				printOne(d2);
			}
			cout << endl;
		}
		else if(pil == 4){
			cout << "Masukkan Date yang ingin diganti(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				gantiOne(d1);
			}
			else{
				gantiOne(&d2);
			}
			cout << endl;
		}
		else if(pil == 5){
			cout << "Masukkan Date yang ingin diganti(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				changeDate(d1);
			}
			else{
				changeDate(&d2);
			}
			cout << endl;
		}
		else if(pil == 6){
			if(*d1 < d2){
				cout << "d1 lebih kecil dari d2" << endl;
			}
			else if(*d1 > d2){
				cout << "d1 lebih besar dari d2" << endl;
			}
			else if(*d1 == d2){
				cout << "d1 sama dengan d2" << endl;
			}
			cout << endl;
		}
		cout << "*********** Driver kelas Date ************" << endl;
		cout << "Silahkan pilih menu dibawah ini :" << endl;
		cout << "1. Konstruktor dengan parameter untuk Date 1"<< endl;
		cout << "2. Print Date"<< endl;
		cout << "3. Print salah satu tanggal (tanggal, bulan, tahun)"<< endl;
		cout << "4. Ganti nilai tanggal/bulan/tahun"<< endl;
		cout << "5. Ganti tanggal keseluruhan" << endl;
		cout << "6. Bandingkan Tanggal"<< endl;
		cout << "Pilihan anda : ";
		cin >> pil;
	}
return 0;
}

void changeDate(Date *d1){
	int d,m,y;
	cout << "Tanggal sebelumnya :" << (*d1) << endl;
	cout << "Masukkan tanggal yang baru :";
	cin >> d;
	cout << "Masukkan bulan yang baru :";
	cin >> m;
	cout << "Masukkan tahun yang baru :";
	cin >> y;
	(*d1).setDate(d,m,y);
	cout << "tanggal setelah diganti :" << (*d1) << endl;
}

void printOne(Date d1){
	int pil2;
	cout << "Masukkan date yang ingin dilihat :" << endl;
	cout << "1. Print tanggal" << endl;
	cout << "2. Print bulan" << endl;
	cout << "3. Print tahun" << endl;
	cout << "Pilihan anda : "; cin >>pil2;
	if(pil2 == 1){
		cout << "Tanggal : " << d1.getDay() << endl;
	}
	else if(pil2 == 2){
		cout << "Bulan : " << d1.getMonth() << endl;
	}
	else if(pil2 == 3){
		cout << "Tahun : " << d1.getYear() << endl;
	}
}

void gantiOne(Date *d1){
	int pil2, temp;
	cout << "Masukkan pilihan yang ingin dilihat :" << endl;
	cout << "1. Ganti tanggal" << endl;
	cout << "2. Ganti bulan" << endl;
	cout << "3. Ganti tahun" << endl;
	cout << "Pilihan anda : "; cin >>pil2;
	if(pil2 == 1){
		cout << "Tanggal sebelumnya : " << (*d1)<< endl;
		cout << "Masukkan tanggal yang baru :";
		cin >> temp;
		(*d1).setDay(temp);
		cout << "Tanggal sesudah diganti : " << (*d1) << endl;
	}
	else if(pil2 == 2){
		cout << "Tanggal sebelumnya : " << (*d1) << endl;
		cout << "Masukkan bulan yang baru :";
		cin >> temp;
		(*d1).setMonth(temp);
		cout << "Tanggal sesudah diganti : " << (*d1)<< endl;
	}
	else if(pil2 == 3){
		cout << "Tanggal sebelumnya : " << (*d1)<< endl;
		cout << "Masukkan tahun yang baru :";
		cin >> temp;
		(*d1).setYear(temp);
		cout << "Tanggal sesudah diganti : " << (*d1)<< endl;
	}
}