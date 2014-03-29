#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class Queue{
public:
	Queue();//CTOR
	Queue(int n); //CTOR param
	Queue(const Queue&); // CCTOR
	~Queue(); // DTOR
	Queue& operator= (const Queue<T>& Q); // Operator=
	friend ostream& operator<< (ostream& os, const Queue Q); // Ostream
	void Add(T x); // Menambahkan ke antrian
	const T Delete(); // Menghapus orang pertama pada antrian
	bool isEmpty() const; // untuk mengecek apakah antrian kosong
	bool isFull() const; // untuk mengecek apakah antrian penuh
	T DeleteLast(); // Menghapus orang terakhir pada antrian
	int NBElmt() const; // Menghitung jumlah element pada queue
	
private:
	T* TQ;
	int Head; // letak head pada antrian
	int Tail; // letak tail pada antrian
	int maxElmt; // jumlah maksimal element(100 jika tidak di tentukan)
	static const int Nil;
};

template <class T>
const int Queue<T>::Nil = -999;

template <class T>
Queue<T>::Queue(){
	Head = Nil;
	Tail = Nil;
	maxElmt = 100; // default max size
	TQ = new T[maxElmt];
}

template <class T>
Queue<T>::Queue(int n){
	Head = Nil;
	Tail = Nil;
	maxElmt = n; // max size defined
	TQ = new T[maxElmt];
}
template <class T>
Queue<T>::Queue(const Queue& Q){
	this->maxElmt = Q.maxElmt;
	this->Head = Q.Head;
	this->Tail = Q.Tail;
	for (int i = Head; i <= Tail; i ++){
		this->TQ[i] = Q.TQ[i];
	}
}
template <class T>
Queue<T>::~Queue(){}
template <class T>
Queue<T>& Queue<T>::operator= (const Queue<T>& Q){
	this->maxElmt = Q.maxElmt;
	this->TQ = new T[this->maxElmt];
	this->Head = Q.Head;
	this->Tail = Q.Tail;
	if(this->Tail < this->Head){
		for(int i = this->Head - 1; i < maxElmt - 1; i++){
			this->TQ[i] = Q.TQ[i];
		}
		for(int i = 0; i <= this->Tail; i++){
			this->TQ[i] = Q.TQ[i];
		}
	}
	else{
		for(int i = 0; i <= Tail; i++){
			this->TQ[i] = Q.TQ[i];
		}
	}
	return *this;
}

template<class T>
ostream& operator<< (ostream& os, const Queue<T> Q){
	if(Q.isEmpty()){
		os << "Antrian Kosong" << endl;
		return os;
	}
	else{
		if(Q.Tail < Q.Head){
			os << "[";
			for(int i = Q.Head - 1; i < Q.maxElmt - 1; i++){
				os << Q.TQ[i] << ",";
			}
			for(int i = 0; i <= Q.Tail; i++){
				if(i != Q.Tail){
					os << Q.TQ[i] << ",";
				}
				else{
					os << Q.TQ[i] << "]" << endl;
				}
			}
			os << endl;
		}
		else{
			os << "[";
			for(int i = Q.Head; i <= Q.Tail; i++){
				if(i != Q.Tail){
					os << Q.TQ[i] << ",";
				}
				else{
					os << Q.TQ[i] << "]";
				}
			}
			os << endl;
		}
		return os;
	}
}
template <class T>
void Queue<T>::Add(T x){
	if(isEmpty()){
		Head = 0; Tail = 0;
		TQ[0] = x; 
	}
	else{
		if(isFull()){
			cout << "Antrian Penuh" << endl;
		}
		else{
			Tail = Tail + 1;
			TQ[Tail] = x;
		}
	}
}
template <class T>
const T Queue<T>::Delete(){
	T temp;
	if(isEmpty()){
		cout << "kosong woi" << endl;
		return 0;
	}
	else if (NBElmt() == 1){
		temp = TQ[Head];
		Head = Nil; Tail = Nil;
	}
	else{
		temp = TQ[Head];
		if (Tail == maxElmt - 1){
			Head = 1;
		}
		else{
			Head = Head + 1;
		}
	}
	return temp;
}
template <class T>
bool Queue<T>::isEmpty() const{
	return (Tail == Nil && Head == Nil);
}
template <class T>
bool Queue<T>::isFull() const{
	return NBElmt() == maxElmt;
}
template <class T>
T Queue<T>::DeleteLast(){
	T temp = TQ[Tail];
	if (NBElmt() == 1){
		Head = 0; Tail = 0;
	}
	else{
		Tail = Tail - 1;
	}
	return temp;
}
template <class T>
int Queue<T>::NBElmt() const{
	if(isEmpty()){
		return 0;
	}
	else{
		if (Tail >= Head){
			return Tail -  Head + 1;		
		}
		else{
			return (maxElmt - (Head - Tail));
		}
	}
}


#endif