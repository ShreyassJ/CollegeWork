
#include <iostream>
#include <fstream>
#include "Data.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::string;
#pragma once

class QueueNode
{
public: // Member functions

    QueueNode();
    QueueNode(Data* newData);
    ~QueueNode();

    Data* getData();
    QueueNode* getNext();
    int getCN();
    int getST();
    int getTT();

    void setCN(int CN);
    void setST(int ST);
    void setTT(int TT);
    void setRST(int RST);
    void setNext(QueueNode* next);

    

private:

    Data* pData;    
    QueueNode* pNext;

};
