#include "Time.h"

/** @name Lima Sekawan
 */
///@{
/** Konstruktor dari kelas Time */
Time::Time(){
	hour = 0;
	minute = 0;
	second = 0;
}

/** Konstruktor dengan parameter dari kelas Time */
Time::Time(int h, int m, int s){
	hour = h;
	minute = m;
	second = s;
}
/** Copy Konstruktor dari kelas Time */
Time::Time(const Time& T){
	hour = T.hour;
	minute = T.minute;
	second = T.second;
}
/** Operator = dari kelas Time */
Time& Time::operator=(const Time& T){
	hour = T.hour;
	minute = T.minute;
	second = T.second;
	return *this;
}
/** Fungsi untuk print(outputstream) dari kelas Time */
ostream& operator<<(ostream& os, const Time& T){
	os << T.getHour() << ":" << T.getMinute() << ":" << T.getSecond();
	return os;
}
/** Destruktor dari kelas Time */
Time::~Time(){}
///@}
/** @name Getter dan Setter kelas Time
 */
///@{
/** Prosedur untuk mengubah nilai hour Time */
void Time::setHour(int h){
	hour = h;
}
/** Prosedur untuk mengubah nilai minute Time */
void Time::setMinute(int m){
	minute = m;
}
/** Prosedur untuk mengubah nilai second pada Time */
void Time::setSecond(int s){
	second = s;
}
/** Prosedur untuk mengubah nilai Time*/
void Time::setTime(int h, int m, int s){
	hour = h;
	minute = m;
	second = s;
}
/** Fungsi yang mengembalikan nilai hour pada Time */
int Time::getHour() const{
	return hour;
}
/** Fungsi yang mengembalikan nilai minute pada Time */
int Time::getMinute() const{
	return minute;
}
/** Fungsi yang mengembalikan nilai second pada Time */
int Time::getSecond() const{
	return second;
}
///@}
/** @name Operator untuk membandingkan dua Time
 */
///@{
/**  Fungsi untuk membandingkan Time, apakah lebih kecil atau tidak*/
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
/**  Fungsi untuk membandingkan Time, apakah sama atau tidak*/
bool operator==(const Time& t1, const Time& t2){
	return (t1.getHour() == t2.getHour() &&
		t1.getMinute() == t2.getMinute() &&
		t1.getSecond() == t2.getSecond());
}
/**  Fungsi untuk membandingkan Time, apakah lebih besar atau tidak*/
bool operator>(const Time& t1, const Time& t2){
	return !(t1 < t2 || t1 == t2);
}
///@}