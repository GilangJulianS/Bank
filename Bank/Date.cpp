#include "Date.h"
/** @name Lima sekawan
 */
///@{
/** Konstruktor kelas Date*/
Date::Date(){
	day = 0;
	month = 0;
	year = 0;
}
/** Konstruktor dengan parameter kelas Date*/
Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}
/** Copy Konstruktor kelas Date*/
Date::Date(const Date& D){
	day = D.day;
	month = D.month;
	year = D.year;
}
/** Operator = kelas Date*/
Date& Date::operator=(const Date& D){
	day = D.day;
	month = D.month;
	year = D.year;
	return *this;
}
/**  fungsi untuk print(outputstream) kelas Date*/
ostream& operator<<(ostream& os, const Date& D){
	os << D.day << "-" << D.month << "-" << D.year;
	return os;
}
/**  Destruktor dari kelas Date*/
Date::~Date(){}
///@}
/** @name Getter dan Setter dari kelas Date
 */
///@{
/**  Prosedur untuk mengubah nilai day*/
void Date::setDay(int d){
	day = d;
}
/**  Prosedur untuk mengubah nilai month*/
void Date::setMonth(int m){
	month = m;
}
/**  Prosedur untuk mengubah nilai year*/
void Date::setYear(int y){
	year = y;
}
/**  Prosedur untuk mengubah nilai tanggal(day, month, dan year)*/
void Date::setDate(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}
/**  Fungsi untuk mendapatkan nilai day*/
int Date::getDay() const{
	return day;
}
/**  Fungsi untuk mendapatkan nilai month*/
int Date::getMonth() const{
	return month;
}
/**  Fungsi untuk mendapatkan nilai year*/
int Date::getYear() const{
	return year;
}
///@}

/** @name Operator untuk membandingkan dua Date
 */
///@{
/**  Fungsi untuk membandingkan tanggal, apakah lebih kecil atau tidak*/
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
/**  Fungsi untuk membandingkan tanggal, apakah sama atau tidak*/
bool operator==(const Date& d1, const Date& d2){
	return (d1.getYear() == d2.getYear() &&
		d1.getMonth() == d2.getMonth() &&
		d1.getDay() == d2.getDay());
}
/**  Fungsi untuk membandingkan tanggal, apakan lebih besar atau tidak*/
bool operator>(const Date& d1, const Date& d2){
	return !(d1 < d2 || d1 == d2);
}
///@}