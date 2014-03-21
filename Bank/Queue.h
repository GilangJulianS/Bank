#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <assert.h>

using namespace std;

class Queue{
public:
	Queue();//CTOR
	Queue(int n); //CTOR param
	Queue(const Queue&); // CCTOR
	~Queue(); // DTOR
	Queue& operator= (const Queue& Q); // Operator=
	friend ostream& operator<< (ostream& os, const Queue& Q); // Ostream
	void Add(int x); // Menambahkan ke antrian
	const int Delete(); // Menghapus orang pertama pada antrian
	bool isEmpty() const; // untuk mengecek apakah antrian kosong
	bool isFull() const; // untuk mengecek apakah antrian penuh
	int DeleteLast(); // Menghapus orang terakhir pada antrian
	int NBElmt() const; // Menghitung jumlah element pada queue
	
private:
	int* TQ;
	int Head; // letak head pada antrian
	int Tail; // letak tail pada antrian
	int maxElmt; // jumlah maksimal element(100 jika tidak di tentukan)
	static const int Nil;
};


#endif