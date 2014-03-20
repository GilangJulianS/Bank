#pragma once
#include <iostream>
#include "Event.h"

using namespace std;

int main(){
	DateTime TMax, currTime;
	Event event;
	int nTeller;
	char* in = new char[100];
	std::cin.getline(in, 100);
	event = Event(in);
	TMax = event.getDateTime();
	cout << TMax;
	cin >> nTeller;
	
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
