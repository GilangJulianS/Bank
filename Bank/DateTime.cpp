#include "DateTime.h"
/** @name Lima Sekawan
 */
///@{
/** Konstruktor kelas DateTime*/
DateTime::DateTime(){
	date = Date();
	time = Time();
}
/** Konstruktor dengan parameter kelas DateTime*/
DateTime::DateTime(int d, int mo, int y, int h, int mi, int s){
	date = Date(d, mo, y);
	time = Time(h, mi, s);
}
/** Copy Konstruktor kelas DateTime*/
DateTime::DateTime(const DateTime& D){
	Date tDate = D.getDate();
	Time tTime = D.getTime();
	date.setDate(tDate.getDay(), tDate.getMonth(), tDate.getYear());
	time.setTime(tTime.getHour(), tTime.getMinute(), tTime.getSecond());
}
/** Operator = kelas DateTime*/
DateTime& DateTime::operator=(const DateTime& D){
	Date tDate = D.getDate();
	Time tTime = D.getTime();
	date.setDate(tDate.getDay(), tDate.getMonth(), tDate.getYear());
	time.setTime(tTime.getHour(), tTime.getMinute(), tTime.getSecond());
	return *this;
}
/** Fungsi untuk print(outputstream) kelas DateTime*/
ostream& operator<<(ostream& os, const DateTime& DT){
	os << DT.date << ";" << DT.time;
	return os;
}
/** Destruktor kelas DateTime*/
DateTime::~DateTime(){}
///@}


char* DateTime::substr(char* str, int s, int n){
	int i = s;
	char* str2 = new char[n];
	for(int j=0; j<n; j++){
		str2[j] = str[i];
		i++;
	}
	return str2;
}

/*int DateTime::findChar(char* str, char c){
	int i = 0;
	while(str[i] != ''){
		if(str[i] == c)
			return i;
		i++;
	}
	return -1;
}*/

/** @name Getter dan Setter dari kelas DateTime
 */
///@{
/** Prosedur untuk mengubah tanggal dan waktu*/
void DateTime::setDateTime(int d, int mo, int y, int h, int mi, int s){
	date.setDate(d, mo, y);
	time.setTime(h, mi, s);
}
/** Fungsi yang mengembalikan tanggal*/
Date DateTime::getDate() const{
	return date;
}
/** Fungsi yang mengembalikan waktu*/
Time DateTime::getTime() const{
	return time;
}
///@}

/** @name Operator untuk membandingkan dua DateTime
 */
///@{
/**  Fungsi untuk membandingkan tanggal dan waktu, apakah lebih kecil atau tidak*/
bool operator<(const DateTime& dt1, const DateTime& dt2){
	if(dt1.getDate() < dt2.getDate())
		return true;
	else if(dt1.getDate() == dt2.getDate()){
		if(dt1.getTime() < dt2.getTime())
			return true;
		else
			return false;
	}
	else
		return false;
}
/**  Fungsi untuk membandingkan tanggal dan waktu, apakah sama atau tidak*/
bool operator==(const DateTime& dt1, const DateTime& dt2){
	return (dt1.getDate() == dt2.getDate() &&
		dt1.getTime() == dt2.getTime());
}
/**  Fungsi untuk membandingkan tanggal dan waktu, apakah lebih besar atau tidak*/
bool operator>(const DateTime& dt1, const DateTime& dt2){
	return !(dt1 < dt2 || dt1 == dt2);
}
///@}