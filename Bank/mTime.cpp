#include "Time.h"
#include <assert.h>

using namespace std;

void printOne(Time t1);
void gantiOne(Time *t1);
void changeTime(Time *t1);

int main(){
	int pil, temp1, temp2, temp3;
	Time* t1;
	Time t2;
	cout << "*********** Driver kelas Time ************" << endl;
	cout << "Silahkan pilih menu dibawah ini :" << endl;
	cout << "1. Konstruktor dengan parameter untuk Time 1"<< endl;
	cout << "2. Print Time"<< endl;
	cout << "3. Print salah satu waktu (jam, menit, detik)"<< endl;
	cout << "4. Ganti nilai jam/menit/detik"<< endl;
	cout << "5. Ganti waktu keseluruhan" << endl;
	cout << "6. Bandingkan waktu"<< endl;
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
			t1 = new Time(temp1, temp2, temp3);	
		}
		else if(pil == 2){
			cout << "Masukkan Time yang ingin dilihat(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				cout << *t1 << endl;
			}
			else{
				cout << t2 << endl;
			}
			cout << endl;
		}
		else if(pil == 3){
			cout << "Masukkan Time yang ingin dilihat(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				printOne(*t1);
			}
			else{
				printOne(t2);
			}
			cout << endl;
		}
		else if(pil == 4){
			cout << "Masukkan Time yang ingin diganti(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				gantiOne(t1);
			}
			else{
				gantiOne(&t2);
			}
			cout << endl;
		}
		else if(pil == 5){
			cout << "Masukkan Time yang ingin diganti(1/2) :";
			cin >> temp1;
			assert(temp1 > 0 && temp1 < 3);
			if (temp1 == 1){
				changeTime(t1);
			}
			else{
				changeTime(&t2);
			}
			cout << endl;
		}
		else if(pil == 6){
			if(*t1 < t2){
				cout << "t1 lebih kecil dari t2" << endl;
			}
			else if(*t1 > t2){
				cout << "t1 lebih besar dari t2" << endl;
			}
			else if(*t1 == t2){
				cout << "t1 sama dengan t2" << endl;
			}
			cout << endl;
		}
		cout << "*********** Driver kelas Time ************" << endl;
		cout << "Silahkan pilih menu dibawah ini :" << endl;
		cout << "1. Konstruktor dengan parameter untuk Time 1"<< endl;
		cout << "2. Print Time"<< endl;
		cout << "3. Print salah satu waktu (jam, menit, detik)"<< endl;
		cout << "4. Ganti nilai jam/menit/detik"<< endl;
		cout << "5. Ganti waktu keseluruhan" << endl;
		cout << "6. Bandingkan waktu"<< endl;
		cout << "Pilihan anda : ";
		cin >> pil;
	}
return 0;
}

void changeTime(Time *t1){
	int h,m,s;
	cout << "Tanggal sebelumnya :" << (*t1) << endl;
	cout << "Masukkan jam yang baru :";
	cin >> h;
	cout << "Masukkan menit yang baru :";
	cin >> m;
	cout << "Masukkan detik yang baru :";
	cin >> s;
	(*t1).setTime(h,m,s);
	cout << "waktu setelah diganti :" << (*t1) << endl;
}

void printOne(Time t1){
	int pil2;
	cout << "Masukkan time yang ingin dilihat :" << endl;
	cout << "1. Print jam" << endl;
	cout << "2. Print menit" << endl;
	cout << "3. Print detik" << endl;
	cout << "Pilihan anda : "; cin >>pil2;
	if(pil2 == 1){
		cout << "Tanggal : " << t1.getHour() << endl;
	}
	else if(pil2 == 2){
		cout << "Bulan : " << t1.getMinute() << endl;
	}
	else if(pil2 == 3){
		cout << "Tahun : " << t1.getSecond() << endl;
	}
}

void gantiOne(Time *t1){
	int pil2, temp;
	cout << "Masukkan pilihan yang ingin dilihat :" << endl;
	cout << "1. Ganti tanggal" << endl;
	cout << "2. Ganti bulan" << endl;
	cout << "3. Ganti tahun" << endl;
	cout << "Pilihan anda : "; cin >>pil2;
	if(pil2 == 1){
		cout << "Waktu sebelumnya : " << (*t1)<< endl;
		cout << "Masukkan jam yang baru :";
		cin >> temp;
		(*t1).setHour(temp);
		cout << "Waktu sesudah diganti : " << (*t1) << endl;
	}
	else if(pil2 == 2){
		cout << "Waktu sebelumnya : " << (*t1) << endl;
		cout << "Masukkan menit yang baru :";
		cin >> temp;
		(*t1).setMinute(temp);
		cout << "Waktu sesudah diganti : " << (*t1) << endl;
	}
	else if(pil2 == 3){
		cout << "Waktu sebelumnya : " << (*t1)<< endl;
		cout << "Masukkan tahun yang baru :";
		cin >> temp;
		(*t1).setSecond(temp);
		cout << "Waktu sesudah diganti : " << (*t1)<< endl;
	}
}