#include "QueueNode.h"

// construcotr
QueueNode::QueueNode(Data* newData) {
	this->pData = newData;
	this->pNext	= nullptr; 
}
QueueNode::QueueNode() {
	this->pData = new Data;
	this->pNext = nullptr;
}
QueueNode::~QueueNode() {
}

// getters
Data* QueueNode::getData() {
	return this->pData;
}
QueueNode* QueueNode::getNext() {
	return this->pNext;
}

// setters
void QueueNode::setNext(QueueNode* next) {
	this->pNext = next;
}

// additional setters for testing purposes
void QueueNode::setCN(int CN) {
	this->pData->setCustomerNumber(CN);
}
void QueueNode::setST(int ST) {
	this->pData->setServiceTime(ST);
}
void QueueNode::setRST(int RST) {
	this->pData->setRandomST(RST);
}
void QueueNode::setTT(int TT) {
	this->pData->setTotalTime(TT);
}

// additional getters for testing purposes
int QueueNode::getCN() {
	return this->pData->getCustomerNumber();
}
int QueueNode::getST() {
	return this->pData->getServiceTime();
}

int QueueNode::getTT() {
	return this->pData->getTotalTime();
}

