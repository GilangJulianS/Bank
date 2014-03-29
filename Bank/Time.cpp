#include "Time.h"

Time::Time(){
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int h, int m, int s){
	hour = h;
	minute = m;
	second = s;
}

Time::Time(const Time& T){
	hour = T.hour;
	minute = T.minute;
	second = T.second;
}

Time& Time::operator=(const Time& T){
	hour = T.hour;
	minute = T.minute;
	second = T.second;
	return *this;
}

ostream& operator<<(ostream& os, const Time& T){
	os << T.getHour() << ":" << T.getMinute() << ":" << T.getSecond();
	return os;
}

Time::~Time(){}

void Time::setHour(int h){
	hour = h;
}

void Time::setMinute(int m){
	minute = m;
}

void Time::setSecond(int s){
	second = s;
}

void Time::setTime(int h, int m, int s){
	hour = h;
	minute = m;
	second = s;
}

int Time::getHour() const{
	return hour;
}

int Time::getMinute() const{
	return minute;
}

int Time::getSecond() const{
	return second;
}

bool operator<(const Time& t1, const Time& t2){
	if(t1.getHour() < t2.getHour())
		return true;
	else if(t1.getHour() == t2.getHour()){
		if(t1.getMinute() < t2.getMinute())
			return true;
		else if(t1.getMinute() == t2.getMinute()){
			if(t1.getSecond() < t2.getSecond())
				return true;
			else 
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool operator==(const Time& t1, const Time& t2){
	return (t1.getHour() == t2.getHour() &&
		t1.getMinute() == t2.getMinute() &&
		t1.getSecond() == t2.getSecond());
}

bool operator>(const Time& t1, const Time& t2){
	return !(t1 < t2 || t1 == t2);
}