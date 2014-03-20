#pragma once
#include "DateTime.h"

class Event{
public:
	Event();
	Event(char* input);
	Event(const Event&);
	Event& operator= (const Event&);
	~Event();

	DateTime getDateTime() const;
	int getType() const;
	int getDepartId() const;
private:
	static const int DEPARTURE;
	static const int ARRIVAL;
	int type;
	int departId;
	DateTime dateTime;
};