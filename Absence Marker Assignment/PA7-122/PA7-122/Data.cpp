#include "Data.h"
//constructor
Data::Data() {
	this->recordNumber = 0;
	this->IDNumber = 0;
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->units = "";
	this->program = "";
	this->level = "";
	this->absences = 0;
}
//constructor
Data::Data(int RecordNumber, int idNumber, string FirstName, string LastName, string Email, string Units, string Program, string Level, int Absences) {
	this->recordNumber = RecordNumber;
	this->IDNumber = idNumber;
	this->firstName = FirstName;
	this->lastName = LastName;
	this->email = Email;
	this->units = Units;
	this->program = Program;
	this->level = Level;
	this->absences = Absences;

}
//destructor
Data::~Data() {
}
//temporary push fucntion that calls push function in stack class
void Data::pushD(string date) {

	latestAbsence.push(date);
}

//temporary peek fucntion that calls peek function in stack class
string Data::peekD() {

	return latestAbsence.peek();

}


//Everything below are getters and setters. 

// I did not use like any of them btw

void Data::setRecordNumber(int RecordNumber) {
	this->recordNumber = RecordNumber;
}
void Data::setIDNumber(int idNumber) {
	this->IDNumber = idNumber;
}
void Data::setFirstName(string FirstName) {
	this->firstName = FirstName;
}
void Data::setLastName(string LastName) {
	this->lastName = LastName;
}
void Data::setEmail(string Email) {
	this->email = Email;
}
void Data::setUnits(string Units) {
	this->units = Units;
}
void Data::setProgram(string Program) {
	this->program = Program;
}
void Data::setLevel(string Level) {
	this->level = Level;
}
void Data::setAbsences(int Absences) {
	this->absences = Absences;
}

int Data::getRecordNUmber() {
	return recordNumber;
}
int Data::getIDNumber() {
	return IDNumber;
}
string Data::getFirstName() {
	return firstName;
}
string Data::getLastName() {
	return lastName;
}
string Data::getEmail() {
	return email;
}
string Data::getUnits() {
	return units;
}
string Data::getProgram() {
	return program;
}
string Data::getLevel() {
	return level;
}
int Data::getAbsences() {
	return absences;
}