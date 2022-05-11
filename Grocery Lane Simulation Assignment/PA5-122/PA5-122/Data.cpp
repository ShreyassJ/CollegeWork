#include "Data.h"

// constructors
Data::Data(int CustomerNumber, int ServiceTime, int TotalTime) {
	this->customerNumber = CustomerNumber;
	this->serviceTime = ServiceTime;
	this->totalTime = TotalTime;
}
Data::Data() {
	this->customerNumber = -1;
	this->serviceTime = -1;
	this->totalTime = -1;
}
Data::~Data() {
}

//setters
void Data::setCustomerNumber(int CustomerNumber) {
	this->customerNumber = CustomerNumber;
}
void Data::setServiceTime(int ServiceTime) {       
	this->serviceTime = ServiceTime;
}
void Data::setTotalTime(int TotalTime) {
	this->totalTime = TotalTime;
}

//getters
int Data::getCustomerNumber() {
	return this->customerNumber;
}
int Data::getServiceTime() {
	return this->serviceTime;
}
int Data::getTotalTime() {
	return this->totalTime;
}

// fucnction creates a random number for the service time for each node when called
int Data::setRandomST(int laneNum) {
	int num = 0;
	if (laneNum == 2) {
		num = (rand() % 4) + 1;
	}
	else if (laneNum == 1) {
		num = (rand() % 5) + 3;
	}
	this->serviceTime = num;
	return num;
}