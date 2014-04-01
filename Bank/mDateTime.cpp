#include "Event.h"
#include <assert.h>

using namespace std;

void printOne(DateTime d1);
void gantiOne(DateTime *d1);
void changeDate(DateTime *d1);

int main(){
	int pil temp1;
	char* in;
	Event ev;
	cout << "*********** Driver kelas Date ************" << endl;
	cout << "Silahkan pilih menu dibawah ini :" << endl;
	cout << "1. Set new Event"<< endl;
	cout << "2. getDateTime"<< endl;
	cout << "3. getType"<< endl;
	cout << "4. getDepartID" << endl;
	cout << "Pilihan anda : ";
	cin >> pil;
	while(pil != 9){
		if (pil == 1){
			cin >> in;
			ev.setNewEvent(in);
		}
		else if(pil == 2){
			cout << ev.getDateTime()endl;
		}
		else if(pil == 3){
			cout << ev.getType() << end;
		}
		else if(pil == 4){
			cout << ev.getDepartId() << endl;
		}
		cout << "*********** Driver kelas Date ************" << endl;
		cout << "Silahkan pilih menu dibawah ini :" << endl;
		cout << "1. Set new Event"<< endl;
		cout << "2. getDateTime"<< endl;
		cout << "3. getType"<< endl;
		cout << "4. getDepartID" << endl;
		cout << "Pilihan anda : ";
		cin >> pil;
	}
return 0;
}
