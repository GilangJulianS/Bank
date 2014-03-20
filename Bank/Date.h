#pragma once
#include <iostream>

using namespace std;

class Date{
public:
	Date();
	Date(int d, int m, int y);
	Date(const Date&);
	Date& operator=(const Date&);
	friend ostream& operator<<(ostream& os, const Date&);
	~Date();

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int d, int m, int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;

protected:
	int day;
	int month;
	int year;
};