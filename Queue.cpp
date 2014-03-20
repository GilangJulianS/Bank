#include "Queue.h"

const int Queue::Nil = -999;

Queue::Queue(){
	Head = Nil;
	Tail = Nil;
	maxElmt = 100;
	TQ = new int[maxElmt];
}
Queue::Queue(int n){
	Head = Nil;
	Tail = Nil;
	maxElmt = n;
	TQ = new int[maxElmt];
}
Queue::Queue(const Queue& Q){
	this->maxElmt = Q.maxElmt;
	this->Head = Q.Head;
	this->Tail = Q.Tail;
	for (int i = Head; i <= Tail; i ++){
		this->TQ[i] = Q.TQ[i];
	}
}
Queue::~Queue(){}
Queue& Queue::operator= (const Queue& Q){
	this->maxElmt = Q.maxElmt;
	this->TQ = new int[this->maxElmt];
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
ostream& operator<< (ostream& os, const Queue& Q){
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
		}
		else{
			os << "[";
			for(int i = 0; i <= Q.Tail; i++){
				if(i != Q.Tail){
					os << Q.TQ[i] << ",";
				}
				else{
					os << Q.TQ[i] << "]";
				}
			}
		}
		return os;
	}
}
void Queue::Add(int x){
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
const int Queue::Delete(){
	int temp;
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
bool Queue::isEmpty() const{
	return (Tail == Nil && Head == Nil);
}
bool Queue::isFull() const{
	return NBElmt() == maxElmt;
}
int Queue::DeleteLast(){
	int temp = TQ[Tail];
	if (NBElmt() == 1){
		Head = 0; Tail = 0;
	}
	else{
		Tail = Tail - 1;
	}
	return temp;
}
int Queue::NBElmt() const{
	if(isEmpty()){
		return 0;
	}
	else{
		return Tail -  Head + 1;
	}
}
