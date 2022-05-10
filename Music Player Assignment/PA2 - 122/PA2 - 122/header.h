#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct duration {
	int seconds;
	int minutes;
}Duration;

typedef struct record {
	char artist[100];
	char albumTitle[100];
	char songTitle[100];
	char genre[100];
	Duration songLength;
	int timesPlayed;
	int rating;
}Record;

typedef struct node {

	Record info;
	struct node* next;
	struct node* previous;
}Node;
Node* load(Node* head);
Node* makeNode(Record data);
void insertFront(Node** albumList, Record data);
void display(Node* albumList, char artist[100]);
void store(Node* head);
void printList(Node* albumList);
void exit_();
void play(Node* albumList);
void rate(Node** albumList);
void edit(Node** albumList, char artist[100]);
Node* deleteNode(Node* head);
void clearBuffer();
Node* insert(Node* head);
char* removeQuotes(char* reQuotes[100]);
Node* sort(Node* head, int numb);
void shuffle(Node* head);