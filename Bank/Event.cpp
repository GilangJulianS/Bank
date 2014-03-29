#include "Event.h"
#include <iostream>
const int Event::DEPARTURE = 0;
const int Event::ARRIVAL =  1;

Event::Event(){
	type = ARRIVAL;
	dateTime = DateTime();
	departId = -1;
}

Event::Event(char* in){
	int d, m, y, h, mi, s;
	d = (in[0] - '0')*10 + (in[1] - '0');
	m = (in[3] - '0')*10 + (in[4] - '0');
	y = (in[6] - '0')*1000 + (in[7] - '0')*100 + (in[8] - '0')*10 + (in[9] - '0');
	h = (in[11] - '0')*10 + (in[12] - '0');
	mi = (in[14] - '0')*10 + (in[15] - '0');
	s = (in[17] - '0')*10 + (in[18] - '0');
	dateTime = DateTime(d, m, y, h, mi, s);
	if(in[20] == 'A'){
		type = ARRIVAL;
		departId = -1;
	}
	else if(in[20] == 'D'){
		type = DEPARTURE;
		departId = generateId(in, 22);
	}
	else{
		type = -1;
		departId = -1;
	}
}

Event::Event(const Event& E){
	type = E.type;
	departId = E.departId;
	dateTime = E.dateTime;
}

Event& Event::operator=(const Event& E){
	type = E.type;
	departId = E.departId;
	dateTime = E.dateTime;
	return *this;
}

Event::~Event(){}

void Event::setNewEvent(char* in){
	int d, m, y, h, mi, s;
	d = (in[0] - '0')*10 + (in[1] - '0');
	m = (in[3] - '0')*10 + (in[4] - '0');
	y = (in[6] - '0')*1000 + (in[7] - '0')*100 + (in[8] - '0')*10 + (in[9] - '0');
	h = (in[11] - '0')*10 + (in[12] - '0');
	mi = (in[14] - '0')*10 + (in[15] - '0');
	s = (in[17] - '0')*10 + (in[18] - '0');
	dateTime = DateTime(d, m, y, h, mi, s);
	if(in[20] == 'A'){
		type = ARRIVAL;
		departId = -1;
	}
	else if(in[20] == 'D'){
		type = DEPARTURE;
		departId = generateId(in, 22);
	}
	else{
		type = -1;
		departId = -1;
	}
}

DateTime Event::getDateTime() const{
	return dateTime;
}

int Event::getType() const{
	return type;
}

int Event::getDepartId() const{
	return departId;
}

int generateId(char* str, int firstId){
	if(str[firstId] == NULL)
		return -1;
	else{
		int tail = generateId(str, firstId+1);
		int power;
		if(tail == -1){
			power = 1;
			tail = 0;
		}
		else
			power = getPower10(tail) * 10;
		return (str[firstId] - '0') * power + tail;
	}
}

int getPower10(int n){
	if(n < 10)
		return 1;
	else
		return 10 * getPower10(n/10);
}
