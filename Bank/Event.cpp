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
		departId = in[22] - '0';
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

DateTime Event::getDateTime() const{
	return dateTime;
}

int Event::getType() const{
	return type;
}

int Event::getDepartId() const{
	return departId;
}
