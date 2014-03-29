#pragma once
#include <iostream>

using namespace std;

class Time{
public:
	Time();
	Time(int h, int m, int s);
	Time(const Time&);
	Time& operator=(const Time&);
	friend ostream& operator<<(ostream& os, const Time&);
	~Time();

	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void setTime(int h, int m, int s);

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	friend bool operator<(const Time& t1, const Time& t2);
	friend bool operator==(const Time& t1, const Time& t2);
	friend bool operator>(const Time& t1, const Time& t2);
protected:
	int hour;
	int minute;
	int second;
};