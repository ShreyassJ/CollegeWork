#include "header.h"

/********************************************************************************************
* Function: void store()								                                    *
* Description: The function stores the data from the current list into the csv file         *
********************************************************************************************/
void store(Node* head) {
	FILE* outfile;
	outfile = fopen("musicPlayList.csv", "w");
	Node* temp = head;
	while (temp != NULL) {
		// prints the entire record's data into the csv file
		fprintf(outfile, "%s,%s,%s,%s,%d:%d,%d,%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
			temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
		temp = temp->next;

	}
	fclose(outfile);
	printf("\n");
	
}
/********************************************************************************************
* Function: void shuffle()								                                    *
* Description: The function creates an array of number that are not repeating and			*
* randomized and then plays the song in that random order.									*
********************************************************************************************/
void shuffle(Node* head) {
	Node* temp = head;
	int order[1000];
	srand(time(0)); 
	int count = 0;
	if (temp != NULL)count++;
	while (temp->next != NULL) {
		temp = temp->next;
		count++;
	}
	// counts the amount of nodes in the list ^^

	for (int i = 0; i < count; i++) {
		int num = 0;
		int r = rand() % count + 1;
		
		for (int j = 0; j < count; j++) {
			if (r != order[j]) {
				num++;
			}
		}
		if (num == count) {
			order[i] = r;
		}
		else {
			i--;
		}

	}
	// creates a series of random numbers that are not repeating ^^

	while (temp->previous != NULL) temp = temp->previous;
		
	for (int m = 0; m < count; m++) {
		printf("%d, ", order[m]); 
	}

	// plays the song like the play fucntion but in the random order from the array created above
	printf("\n");
	for (int k = 0; k < count; k++) {
		for (int l = 0; l < order[k]-1; l++) {
			temp = temp->next;

		}
		system("cls");
		printf("%s, %s, %s, %s, 0%d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
			temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
		Sleep(3000);
		while (temp->previous != NULL) temp = temp->previous; 
	}
	system("cls");

}
/********************************************************************************************
* Function: void insert()								                                    *
* Description: The function asks the user for the data of a new record and then proceeds	*
* to insert the record to the fornt of the list												*
********************************************************************************************/
Node* insert(Node* head) {
	Record REC;
	char text[100];

	printf("What is the name of the artist?\n");
	clearBuffer();
	scanf("%99[^\n]", &text);
	strcpy(REC.artist, &text);

	printf("What is the name of the album?\n");
	clearBuffer();
	scanf("%99[^\n]", &text);
	strcpy(REC.albumTitle, &text);

	printf("What is the name of the song?\n");
	clearBuffer();
	scanf("%99[^\n]", &text);
	strcpy(REC.songTitle, &text);

	printf("What is the name of the genre?\n");
	clearBuffer();
	scanf("%99[^\n]", &text);
	strcpy(REC.genre, &text);

	printf("How long is the song? Example answer: 4:32\n");
	clearBuffer();
	scanf("%99[^\n]", &text);
	
	char* token;
	token = strtok(text, ":");
	REC.songLength.minutes = atoi(token);
	token = strtok(NULL, ":");
	REC.songLength.seconds = atoi(token);

	int num = 0;
	printf("How many times was the song played?\n");
	clearBuffer();
	scanf("%d", &num);
	REC.timesPlayed = num;

	printf("What is the song's rating?\n");
	scanf("%d", &num);
	REC.rating = num;
	// Creating the record that will be created into a node ^^


	// insert it to the fornt
	insertFront(&head, REC);
	return head;
		
}
/********************************************************************************************
* Function: void clearBuffer()								                                *
* Description: clears and chracters still within the buffer and stop at the end of the line	*
********************************************************************************************/
void clearBuffer() {
	int c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
	// Note: this is somthing simple i got from stack overflow because i had issues where the buffer wasnt cleared and when i asked for a string with spaces the code would not work
	// It essentialy clears the buffer so I don't run into any errors when running the program
}
/********************************************************************************************
* Function: void Node* sort()								                                *
* Description: The sort function uses bubble sort in order to sort based on the specified	*
* item to be sorted on ( album title, artist, rating, tiems played)							*
********************************************************************************************/
Node* sort(Node* head, int numb) {

	// Sort uses bubble sort
	
		for (int j = 0; j < 1; j++) {
			int i = 1;
			Node* pTemp = head;
			while (i == 1) {

				if (pTemp->next != NULL) {
					if (numb == 1) {
						// compares the the names of the arist
						if (strcmp(pTemp->info.artist, pTemp->next->info.artist) > 0) {

							//swap
							// rereanges the nodes at the ->next and the ->previous for the swapped node and the node after and the node previous to it
							if (pTemp->previous != NULL) {
								pTemp->previous->next = pTemp->next;
								pTemp->next->previous = pTemp->previous;
							}
							else {
								pTemp->next->previous = NULL;
							}
							pTemp->previous = pTemp->next;
							if (pTemp->next->next != NULL) {
								pTemp->next = pTemp->previous->next;
								pTemp->next->previous = pTemp;
							}
							else {
								pTemp->next = NULL;
							}
							pTemp->previous->next = pTemp;
							///

							if (j == 0) {
								j--;
							}
						}
						else {
							pTemp = pTemp->next;
							// moves onto the next node
						}
					}
					///

					// everyrthing below is a copy but comapring album title, rating, and times played
					if (numb == 2) {
						if (strcmp(pTemp->info.albumTitle, pTemp->next->info.albumTitle) > 0) {

							//swap

							if (pTemp->previous != NULL) {
								pTemp->previous->next = pTemp->next;
								pTemp->next->previous = pTemp->previous;
							}
							else {
								pTemp->next->previous = NULL;
							}
							pTemp->previous = pTemp->next;
							if (pTemp->next->next != NULL) {
								pTemp->next = pTemp->previous->next;
								pTemp->next->previous = pTemp;
							}
							else {
								pTemp->next = NULL;
							}
							pTemp->previous->next = pTemp;


							if (j == 0) {
								j--;
							}
						}
						else {
							pTemp = pTemp->next;
						}
					}
					///
					if (numb == 3) {
						if (pTemp->info.rating > pTemp->next->info.rating) {

							//swap

							if (pTemp->previous != NULL) {
								pTemp->previous->next = pTemp->next;
								pTemp->next->previous = pTemp->previous;
							}
							else {
								pTemp->next->previous = NULL;
							}
							pTemp->previous = pTemp->next;
							if (pTemp->next->next != NULL) {
								pTemp->next = pTemp->previous->next;
								pTemp->next->previous = pTemp;
							}
							else {
								pTemp->next = NULL;
							}
							pTemp->previous->next = pTemp;


							if (j == 0) {
								j--;
							}
						}
						else {
							pTemp = pTemp->next;
						}
					}
					///
					if (numb == 4) {
						if (pTemp->info.timesPlayed < pTemp->next->info.timesPlayed) {

							//swap

							if (pTemp->previous != NULL) {
								pTemp->previous->next = pTemp->next;
								pTemp->next->previous = pTemp->previous;
							}
							else {
								pTemp->next->previous = NULL;
							}
							pTemp->previous = pTemp->next;
							if (pTemp->next->next != NULL) {
								pTemp->next = pTemp->previous->next;
								pTemp->next->previous = pTemp;
							}
							else {
								pTemp->next = NULL;
							}
							pTemp->previous->next = pTemp;


							if (j == 0) {
								j--;
							}
						}
						else {
							pTemp = pTemp->next;
						}
					}

				}
				else i = 0;
			}



		}
	
	//returning the head of the linkedlist and not the middle
	for (int k = 0; k < 1; k++) {
		if (head->previous != NULL) {
			head = head->previous;
			k--;
		}
	}
	
	
	return head;

}
/********************************************************************************************
* Function: Node* deleteNode()								                                *
* Description: This function deletes the node of whatever song the user provides. It		*
* searches the list for the song and deletes it form the list once found					*
********************************************************************************************/
Node* deleteNode(Node* head) {
	Node* pTemp = head;
	Node* pTemp2 = head;
	char text[100];

	printf("What is the name of the song you want to delete?\n");

	clearBuffer();

	scanf("%99[^\n]", &text);


	int count = 0;
	if (strcmp(pTemp->info.songTitle, text) == 0) {
		pTemp->next->previous = NULL;
		head = pTemp->next;
		free(pTemp);

		return head;
	}
	// searches for the ssong
	else {

		while (strcmp(pTemp->info.songTitle, text) != 0) {
			pTemp = pTemp->next;
			
		}
		// rereanges the -> previous and ->next for the nodes before and after
		if (pTemp != NULL) {
			if (pTemp->next != NULL) pTemp->next->previous = pTemp->previous;
			if (pTemp->previous != NULL && pTemp->next != NULL) {
				pTemp->previous->next = pTemp->previous;
			}
			else if (pTemp->previous != NULL && pTemp->next == NULL) {
				pTemp->previous->next = NULL;
			}
			
			
			free(pTemp);
			// deletes the node
		}


	}

	return head;

}
/********************************************************************************************
* Function: Node* load()								                                    *
* Description: This function lets you lets you load all the records form the csv file into a*
* linked list that you will be able to use for other needs									*
********************************************************************************************/
Node* load(Node* head) {
	FILE* infile = fopen("musicPlayList.csv", "r");
	Node* Head = NULL;
	char line[250] = "";
	char temp[250] = "";
	char temp2[250] = "";
	int positions[10];

	if (infile != NULL)
	{
		char* val;


		while (fgets(line, 250, infile) != NULL)//(!feof(infile))
		{
			Record REC;
			strcpy(temp2, line);
			strcpy(temp, line);

			// used the same concept from last PA in order to record all the data
			val = strchr(line, ',');
			if (strchr(line, '"') != NULL) {
				val = strchr(val + 1, ',');
			}

			for (int i = 0; i < 5; i++) {
				positions[i] = val - line;
				//printf("%d, ", positions[i]);
				val = strchr(val + 1, ',');
			}
			positions[5] = val - line;
			/*for (int i = 0; i < 6; i++) {
				printf("%d, ", positions[i]);
			}*/

			int num = 0;
			while (*(temp + num) != '\0') num++;

			// Records all data into a 'Record'
			strncpy(REC.artist, temp, positions[0]);
			REC.artist[positions[0]] = '\0';

			strncpy(REC.albumTitle, temp + positions[0] + 1, positions[1] - 1 - positions[0]);
			REC.albumTitle[positions[1] - 1 - positions[0]] = '\0';

			strncpy(REC.songTitle, temp + positions[1] + 1, positions[2] - 1 - positions[1]);
			REC.songTitle[positions[2] - 1 - positions[1]] = '\0';

			strncpy(REC.genre, temp + positions[2] + 1, positions[3] - 1 - positions[2]);
			REC.genre[positions[3] - 1 - positions[2]] = '\0';

			char timeTemp[100];
			strncpy(timeTemp, temp + positions[3] + 1, positions[4] - 1 - positions[3]);
			timeTemp[positions[4] - 1 - positions[3]] = '\0';

			// The code below is for the time and converting the string into minutes and seconds
			char* token;
			token = strtok(timeTemp, ":");
			REC.songLength.minutes = atoi(token);
			token = strtok(NULL, ":");
			REC.songLength.seconds = atoi(token);


			
			char tempString[100];
			strncpy(tempString, temp + positions[4] + 1, positions[5] - 1 - positions[4]);
			tempString[positions[5] - 1 - positions[4]] = '\0';
			REC.timesPlayed = atoi(tempString);

			strncpy(tempString, temp + positions[5] + 1, 1);
			tempString[1] = '\0';
			REC.rating = atoi(tempString);

			// mkaes that record into a node and places it at the fornt of the linked lsit
			insertFront(&Head, REC);
			
		}

	}
	fclose(infile);
	return Head;
}

/********************************************************************************************
* Function: Node* makeNode()							                                    *
* Description: This function is used to amke the nodes that hold each records. It is		*
* usually called through a seperate function called insertFront								*
********************************************************************************************/
Node* makeNode(Record data) {
	Node* pRec = (Node*)malloc(sizeof(Node));
	if (pRec != NULL) {
		// turns all the data form the record into a node
		strcpy(pRec->info.artist, data.artist);
		strcpy(pRec->info.albumTitle, data.albumTitle);
		strcpy(pRec->info.songTitle, data.songTitle);
		strcpy(pRec->info.genre, data.genre);
		pRec->info.rating = data.rating;
		pRec->info.timesPlayed = data.timesPlayed;
		pRec->info.songLength.seconds = data.songLength.seconds;
		pRec->info.songLength.minutes = data.songLength.minutes;

		pRec->next = NULL;
		pRec->previous = NULL;
	}
	return pRec;
}

/********************************************************************************************
* Function: void insertFront()							                                    *
* Description: This function takes the data from a record, calls a function that maes a		*
* node, then inserts that node to the front of the linked list								*
********************************************************************************************/
void insertFront(Node** albumList, Record data) {
	Node* pRecord = makeNode(data);

	// places the node at the fornt
	if (pRecord != NULL) {

		// the next record is the previous top record
		pRecord->next = *albumList;
		pRecord->previous = NULL;

		if (*albumList != NULL) {
			// vice verse since its a double linked list
			(*albumList)->previous = pRecord;

		}
		*albumList = pRecord;
	}

}

/********************************************************************************************
* Function: void display()																	*
* Description: This fucntion dispalys all the records. You also ahve the option to only		*
* display songs form a certain artist														*
********************************************************************************************/
void display(Node* albumList, char artist[100]) {
	Node* temp = albumList;
	
	printf("\n");
	// checks to see if the user wanted to display songs for a certain artist or not
	if (strcmp(artist, "none") != 0) {
		while (temp != NULL) {

			if (strcmp(temp->info.artist, artist) == 0) {
				// displays song for certain artist ^^
				printf("%s, %s, %s, %s, 0%d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
					temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
				temp = temp->next;
			}
			else {
				temp = temp->next;
			}
		}
		printf("\n");
	}
	else {
		// else prints out the enitre linked list
		while (temp != NULL) {
			if (temp->info.songLength.minutes > 9) {
				printf("%s, %s, %s, %s, %d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
					temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
				temp = temp->next;
			}
			else {
				printf("%s, %s, %s, %s, 0%d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
					temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
				temp = temp->next;
			}

		}
		printf("\n");
	}

}



/********************************************************************************************
* Function: void edit()																		*
* Description: This fucntion allows you to edit records. You will be asked for an artist's	*
* name and then you will be allowed to edit parts of the record for the artists songs		*
********************************************************************************************/
void edit(Node** albumList, char artist[100]) {
	Node* temp = albumList;
	int des = 0;

	while (temp != NULL) {
		// finds the artist that the user want to edit
		if (strcmp(temp->info.artist, artist) == 0) {
			printf("\n%s, %s, %s, %s, 0%d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
				temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
			printf("Would you like to edit this entry?( type 1 for yes and 2 for no)\nIf the artist has another record typing 2 will cycle through the rest of the artist's songs\n");
			scanf("%d", &des);
			if (des == 1) {
				int i = 0;
				// cycles through all the artist's songs asking which one they would like to edit
				while (i == 0) {
					printf("What would you like to edit? (1 for artist, 2 for album title, 3 for song title, 4 for genre, 5 for minutes (song length), 6 for seconds (song length), 7 for times played, 8 for rating)\n");
					scanf("%d", &des);
					char test[100];
					// switch for editing each part of the record
					switch (des) {
					case 1:
						printf("Type what you would like to change it too:\n");
						clearBuffer();
						scanf("%99[^\n]", &test);
						strcpy(temp->info.artist, test);
						break;
					case 2:
						printf("Type what you would like to change it too:\n");
						clearBuffer();
						scanf("%99[^\n]", &test);
						strcpy(temp->info.albumTitle, test);
						break;
					case 3:
						printf("Type what you would like to change it too:\n");
						clearBuffer();
						scanf("%99[^\n]", &test);
						strcpy(temp->info.songTitle, test);
						break;
					case 4:
						printf("Type what you would like to change it too:\n");
						clearBuffer();
						scanf("%99[^\n]", &test);
						strcpy(temp->info.genre, test);
						break;
					case 5:
						printf("Type what you would like to change it too:\n");
						scanf("%d", &des);
						temp->info.songLength.minutes = des;
						break;
					case 6:
						printf("Type what you would like to change it too:\n");
						scanf("%d", &des);
						temp->info.songLength.seconds = des;
						break;
					case 7:
						printf("Type what you would like to change it too:\n");
						scanf("%d", &des);
						temp->info.timesPlayed = des;
						break;
					case 8:
						printf("Type what you would like to change it too:\n");
						scanf("%d", &des);
						temp->info.rating = des;
						break;
					}
					printf("Would you like to edit more for this record? Type 1 for yes and 2 for no\n");
					scanf("%d", &des);
					if (des == 2) {
						i = 1;
					}

				}
			}
			temp = temp->next;
		}

		else {

			temp = temp->next;
		}
	}
	printf("\n");

}

/********************************************************************************************
* Function: void rate()																		*
* Description: This fucntion allows you to change the rating on a specific song. It will	* 
* cycle through every song asking if you would like to change it							*
********************************************************************************************/
void rate(Node** albumList) {
	Node* temp = albumList;
	int des = 0;
	// recycled code form other functions asking if they would like to change the rating
	while (temp != NULL) {


		printf("%s, %s, %s, %s, 0%d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
			temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);

		printf("Would you like to change the rating for this entry?( type 1 for yes and 2 for no)\nIf the artist has multiple records typing 2 will cycle thorugh the rest until the artists has no more\n");
		scanf("%d", &des);
		if (des == 1) {

			printf("What would you like to change it too?\n");
			scanf("%d", &des);
			temp->info.rating = des;


		}
		else {

		}

		temp = temp->next;

	}
	printf("\n");

}

/********************************************************************************************
* Function: void printList()																*
* Description: This fucntion prints all the records in the current linked list				*
********************************************************************************************/
void printList(Node* albumList) {
	Node* temp = albumList;
	// prints entire linkedlist
	while (temp != NULL) {
		if (temp->info.songLength.minutes > 9) {
			printf("%s, %s, %s, %s, %d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
				temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
			temp = temp->next;
		}
		else {
			printf("%s, %s, %s, %s, 0%d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
				temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
			temp = temp->next;
		}

	}
	printf("\n");

}

/********************************************************************************************
* Function: void play()																		*
* Description: Theis function allows you to choose a song form the list. It wil then play	*
* that track for 5 seconds before moving onto the next until it reaches the end				*
********************************************************************************************/
void play(Node* albumList) {
	Node* temp = albumList;
	int descisison = 0;
	char artist[100];
	printf("These are the current songs\n");
	printf("Type the name of the song you want to start at\n");
	clearBuffer();
	scanf("%99[^\n]", &artist);
	
	// makes you choose the song that user would liek to start at
	while (strcmp(artist, temp->info.songTitle) != 0) {
		temp = temp->next;
	}
	
	while (temp != NULL) {

		system("cls");
		printf("%s, %s, %s, %s, 0%d:%d, Play Count:%d, Rating:%d\n", temp->info.artist, temp->info.albumTitle, temp->info.songTitle, temp->info.genre,
			temp->info.songLength.minutes, temp->info.songLength.seconds, temp->info.timesPlayed, temp->info.rating);
		temp = temp->next;

		// cycles through all the songs at a 5 seconds interval until it raches the end of the linked list
		Sleep(3000);

	}
}

// I dont think i need a description for this
void exit_() {
	exit(0);
}