#include <iostream>
#include <fstream>
#include "recordStack.h"
using namespace std;

#pragma once
class Data
{
public:
	Data();
	Data(int RecordNumber, int idNumber, string FirstName, string LastName, string Email, string Units, string Program, string Level, int Absences);
	~Data();

	void setRecordNumber(int RecordNumber);
	void setIDNumber(int idNumber);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmail(string Email);
	void setUnits(string Units);
	void setProgram(string Program);
	void setLevel(string Level);
	void setAbsences(int Absences);

	int getRecordNUmber();
	int getIDNumber();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getUnits();
	string getProgram();
	string getLevel();
	int getAbsences(); 

	string peekD();

	void pushD(string date);

private:
	int recordNumber;
	int IDNumber;
	string firstName;
	string lastName;
	string email;
	string units;
	string program;
	string level;
	int absences;
	recordStack latestAbsence;
};

