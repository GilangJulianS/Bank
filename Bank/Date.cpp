#include "Date.h"

Date::Date(){
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}

Date::Date(const Date& D){
	day = D.day;
	month = D.month;
	year = D.year;
}

Date& Date::operator=(const Date& D){
	day = D.day;
	month = D.month;
	year = D.year;
	return *this;
}

ostream& operator<<(ostream& os, const Date& D){
	os << D.day << "-" << D.month << "-" << D.year;
	return os;
}

Date::~Date(){}

void Date::setDay(int d){
	day = d;
}

void Date::setMonth(int m){
	month = m;
}

void Date::setYear(int y){
	year = y;
}

void Date::setDate(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}

int Date::getDay() const{
	return day;
}

int Date::getMonth() const{
	return month;
}

int Date::getYear() const{
	return year;
}

bool operator<(const Date& d1, const Date& d2){
	if(d1.getYear() < d2.getYear())
		return true;
	else if(d1.getYear() == d2.getYear()){
		if(d1.getMonth() < d2.getMonth())
			return true;
		else if(d1.getMonth() == d2.getMonth()){
			if(d1.getDay() < d2.getDay())
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