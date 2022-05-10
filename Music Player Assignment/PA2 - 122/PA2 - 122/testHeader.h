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


void insertT();
void deleteNodeT();
void shuffleT();