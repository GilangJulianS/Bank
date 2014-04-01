#pragma once
#include "DateTime.h"

class Event{
public:

	static const int DEPARTURE;
	static const int ARRIVAL;

	Event();
	Event(char* in);
	Event(const Event&);
	Event& operator= (const Event&);
	~Event();

	void setNewEvent(char* in);
	DateTime getDateTime() const;
	int getType() const;
	int getDepartId() const;
private:
	
	int type;
	int departId;
	DateTime dateTime;
	int generateId(char* str, int firstIdx);
	int getPower10(int);
};