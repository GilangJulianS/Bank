#pragma once
#include <iostream>
#include "Date.h"
#include "Time.h"

using namespace std;

class DateTime{
public:
	DateTime();
	DateTime(int d, int mo, int y, int h, int mi, int s);
	DateTime(const DateTime&);
	DateTime& operator=(const DateTime&);
	friend ostream& operator<<(ostream& os, const DateTime& DT);
	~DateTime();

	void setDateTime(int d, int mo, int y, int h, int mi, int s);
	Date getDate() const;
	Time getTime() const;

	friend bool operator<(const DateTime& dt1, const DateTime& dt2);
	friend bool operator==(const DateTime& dt1, const DateTime& dt2);
	friend bool operator>(const DateTime& dt1, const DateTime& dt2);
private:
	Date date;
	Time time;
	char* substr(char* str, int s, int n);
	int findChar(char* str, char c);
};