#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>
#include "Data.h"
#include "QueueNode.h"
#include "Queue.h"
using namespace std;

/********************************************************************************************
* Function: main()																			*
* Description: This runs the code for the test cases as well as the normal code that		*
* simulates 2 grocery lanes																	*
********************************************************************************************/
int main() {
	srand(time(NULL));
	// testing test case 1
	cout << "Test Case 1: " << endl;
	Queue testQ;
	testQ.enqueue(1, 1);
	testQ.printQueue(testQ.getHead(), 1);
	Sleep(3000);

	// testing test case 2
	cout << "Test Case 2: " << endl;
	Queue testQ2;
	testQ2.enqueue(1, 1);
	testQ2.enqueue(1, 1);
	testQ2.printQueue(testQ2.getHead(), 1);
	Sleep(3000);

	// testing test case 3
	cout << "Test Case 3: " << endl;
	testQ.dequeue();
	cout << "(prints nothing)" << endl;
	Sleep(3000);

	// testing test case 4
	cout << "Test Case 4: " << endl;
	testQ2.dequeue();
	testQ2.printQueue(testQ2.getHead(), 1);

	// asking how for how long the code should be run for
	Sleep(3000);
	int option = 0;
	cout << "How many minutes would you like to run the code for?: " << endl;
	cin >> option;
	
	Queue standardLane;
	Queue expressLane;
	cout << "Normal code: " << endl;
	cout << "(Each time the Queue prints is 1 minute intervals) " << endl;

	
	
	int check = 0, standardRan = 0, expressRan = 0, standardCount = 1, expressCount = 1, standardTotalTime = 0, expressTotalTime = 0, timeS = 0, timeE = 0;;
	standardLane.enqueue(standardCount, 1);
	expressLane.enqueue(expressCount, 1);
	int count = 0;
	while (check == 0) {
		// creating random numbers for when a new person arrives at a lane
		if (standardRan == 0) {
			
			standardRan = (rand() % 5) + 3;
		}
		if (expressRan == 0) {
			expressRan = (rand() % 4) + 1;
		}
		
		

		standardLane.printQueue(standardLane.getHead(), 1);
		expressLane.printQueue(expressLane.getHead(), 2);
		// 1 minute intervals
		Sleep(60000);
		timeS++;
		timeE++;
		
		int hold = 0;
		QueueNode* temp = NULL;
		QueueNode* temp2 = NULL;

		
		if (standardLane.getHead() != NULL ) {
			
			temp = standardLane.getHead();
		}
		if (expressLane.getHead() != NULL) {
			temp2 = expressLane.getHead();
		}// not used in final code
		

		// code below used to remove someonme form the front of the lane
		if (standardLane.getHead() != NULL) {
			if (timeS >= standardLane.getHead()->getTT()) {
				standardLane.dequeue();
			}
		}
		if (expressLane.getHead() != NULL) {
			if (timeE >= expressLane.getHead()->getTT()) {
				expressLane.dequeue();
			}
		}
		// used for a lane emptys out, resets the lanes 'persoanl timer'
		if (standardLane.getHead() == NULL) {
			timeS = 0;
		}
		if (expressLane.getHead() == NULL) {
			timeE = 0;
		}

		// used to add a new perosn to the lane
		standardRan--;
		expressRan--;
		if (standardRan == 0) {
			standardCount++;
			standardLane.enqueue(standardCount, 1);

		}
		
		if (expressRan == 0) {

			expressCount++;
			expressLane.enqueue(expressCount, 1); 


		}
		// code resets customers number to 1 after 34 hours
		count++;
		if (count > 1440) {
			standardCount == 0;
			expressCount == 0;
		}
		// exits after n minutes
		if (count >= option) {
			exit(0);
		}
	}

	return 0;
}
