#include "Queue.h"

// contructor
Queue::Queue() {
	this->pHead = NULL;
	this->pTail = NULL;
}

Queue::~Queue() {
}

// getters
QueueNode* Queue::getHead() {
	return this->pHead;
}
QueueNode* Queue::getTail() {
	return this->pTail;
}	

//setters
void Queue::setHead(QueueNode* head) {
	this->pHead = head;
}
void Queue::setTail(QueueNode* tail) {
	this->pTail = tail;
}

/********************************************************************************************
* Function: dequeue()																	    *
* Description: This function removes the first node in the queue. it creates a temp node	*
* replaces the new head node with the next node and frees the temp							*
********************************************************************************************/
void Queue::dequeue() {
	QueueNode* temp = NULL;
	temp = this->pHead;
	
	this->pHead = temp->getNext();
	if (temp->getNext() == NULL) this->pTail = NULL;
	free(temp);
}


/********************************************************************************************
* Function: enqueue()																	    *
* Description: This function creates a node with the data inputted, adds the node to the	*
* end of the queue, and checks if the head and tail are all pointing to the corrects node	*
********************************************************************************************/
void Queue::enqueue(int cNum, int lNum) { 
	QueueNode* newNode = new QueueNode();
	QueueNode* temp = NULL;
	QueueNode* tempN = NULL;
	int  total = 0;
	
	
	
	newNode->setCN(cNum);
	newNode->setRST(lNum);
	
	tempN = this->pHead;
	temp = this->pHead;
	
	while (temp != NULL) {
		total += temp->getData()->getServiceTime();
		temp = temp->getNext();
	}
	total += newNode->getData()->getServiceTime();
	newNode->setTT(total);
	if (this->pHead == NULL)this->pHead = newNode;
	
	else if (this->pHead != NULL)this->pTail->setNext(newNode);
	this->pTail = newNode;
	if (this->pHead == NULL) {
	}
	else {
	}
}


// prints the queue
void Queue::printQueue(QueueNode* head, int lane) {
	QueueNode* temp = NULL;
	temp = head;
	cout << "------------------------------------------------------------------------------" << endl;
	while (temp != NULL) {
		if (lane == 1) {
			cout << "Lane Type: Standard Lane" << endl;
		}
		else if (lane == 2) {
			cout << "Lane Type: Express Lane" << endl;
		}
		cout << "Customer Number: " << temp->getData()->getCustomerNumber() << endl;
		cout << "Service Time: " << temp->getData()->getServiceTime() << endl;
		cout << "Total Reamining Time: " << temp->getData()->getTotalTime() << endl << endl;
		temp = temp->getNext();
	}


	cout << "------------------------------------------------------------------------------" << endl<< endl;
	
}
