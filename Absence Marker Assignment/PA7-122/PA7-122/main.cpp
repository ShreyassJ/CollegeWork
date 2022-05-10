#include "Data.h"
#include "recordNode.h"
#include "recordList.h"
using namespace std;

/********************************************************************************************
* Function: main()																			*
* Description: Creates a list and asks the users multiple options to choose from ranging	*
* from loading records to storing master record and adding abscences						*
********************************************************************************************/
int main(void) {
	int x = 0;
	recordList<int> list;
	 
	while (x == 0) {

		list.displayOptions();
		int q = 0;
		int option = 0;

		cin >> option;

		switch (option) {
		case 1:
			list.loadList();
			break;
		case 2:
			list.loadMaster();
			break;
		case 3:
			list.storeList();
			break;
		case 4:
			list.changeAbsence();
			break;
		case 5:
			cout << "Would you like to look at the entire report card (type 0)" << endl << "Would you like a report of student over a certain amount of absences (type 1)" << endl;
			cin >> q;
			if (q == 0) {
				list.displayReport(0);
			}
			else if (q == 1) {
				cout << "Enter amount of abscences student must have or exceed:" << endl;
				cin >> q;
				list.displayReport(q);
			}
			break;
		case 6:
			exit(0);
			break;
		}

	}

	return 0;

}