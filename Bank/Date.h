/** Date Class. Kelas untuk menampung tanggal */

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

	friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator==(const Date& d1, const Date& d2);
	friend bool operator>(const Date& d1, const Date& d2);
protected:
	int day; /*!< Attribute yang menyatakan hari */
	int month; /*!< Attribute yang menyatakan bulan */
	int year; /*!< Attribute yang menyatakan tahun */
};