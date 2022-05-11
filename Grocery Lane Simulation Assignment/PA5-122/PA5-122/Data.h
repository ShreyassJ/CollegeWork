#include <iostream>
#include <fstream>
#include <stdlib.h>    
#include <time.h> 
#include <random>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::string;
#pragma once

class Data
{
public: 
    Data(int CustomerNumber, int ServiceTime, int TotalTime);
    Data();
    ~Data();

    void setCustomerNumber(int CustomerNumber);
    void setServiceTime(int ServiceTime);
    void setTotalTime(int TotalTime);

    int getCustomerNumber();
    int getServiceTime();
    int getTotalTime();

    int setRandomST(int laneNum);


private:

    int customerNumber;
    int serviceTime;   
    int totalTime;    
};