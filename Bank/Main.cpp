#pragma once
#include <iostream>
#include <queue>
#include "Queue.h"
#include "Event.h"
#include "Teller.h"
#include <string>

using namespace std;

int jockeying(int origin);

Teller* tellers;
int nTeller;

int main(){
	DateTime TMax, currTime;
	Event event;
	int pil;
	int lastCustomerId = 0;
	char* in = new char[100];
	char* sampah = new char[100];
	cout << "Masukkan 1" << endl;
	cin >> pil;
	cin.getline(sampah, 100);
	cout << "Masukkan TMax" << endl;
	cin.getline(in, 100);
	event.setNewEvent(in);
	TMax = event.getDateTime();
	cout << "Masukkan jumlah teller" << endl;
	cin >> nTeller;
	cin.getline(sampah, 100);
	tellers = new Teller[nTeller];
	if(pil == 1){
		while(true){
			cout << "Masukkan event" << endl;
			cin.getline(in, 100);
			event.setNewEvent(in);
			if(event.getType() == Event::ARRIVAL){
				int dstIdx, custMin;
				custMin = 999;
				for(int i=0; i<nTeller; i++){
					int temp;
					temp = tellers[i].getCustomerCount();
					if(temp < custMin){
						custMin = temp;
						dstIdx = i;
					}
				}
				lastCustomerId++;
				tellers[dstIdx].addCustomer(lastCustomerId);
			}
			else if(event.getType() == Event::DEPARTURE){
				int tellerIdx = 0;
				for(int i=0; i<nTeller; i++){
					if(tellers[i].getFrontCustomerId() == event.getDepartId())
						tellerIdx = i;
				}
				tellers[tellerIdx].processCustomer();
				int jockey = jockeying(tellerIdx);
				if(jockey != -1){
					tellers[jockey].jockey(tellers[tellerIdx].jockey());
				}
			}
			for(int i=0; i<nTeller; i++){
				if(tellers[i].isServing())	
					cout << tellers[i] << endl;
			}
		}
	}
	// <Create List of Teller> \\

	while(/* currTime < TMax */ true){
		std::cin.getline(in, 100);
		event = Event(in);
		currTime = event.getDateTime();
		// <Add or Remove Queue Element>
	}

	std::cin >> in;
	return 0;
}

int jockeying(int origin){
	bool found = false;
	int i = 0;
	while(i<nTeller && !found){
		if(tellers[origin].getCustomerCount() - tellers[i].getCustomerCount() >= 2)
			found = true;
		i++;
	}
	if(found)
		return i-1;
	else
		return -1;
}