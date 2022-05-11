
#include <iostream>
#include <fstream>
#include "QueueNode.h"
#include "Data.h"
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::string;
#pragma once
class Queue
{
public: // Member functions
    Queue();
   //Queue(QueueNode* head, QueueNode* tail);
    ~Queue();

    QueueNode* getHead();
    QueueNode* getTail();

    void setHead(QueueNode* head);
    void setTail(QueueNode* tail);

    void dequeue();
    void enqueue(int cNum, int lNum);

    void printQueue(QueueNode* head, int lane);

private:

    QueueNode* pHead;
    QueueNode* pTail;


};
