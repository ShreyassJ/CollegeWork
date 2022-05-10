#include "testHeader.h"

void insertT() {
	Record REC;
	char text[100];

	
	strcpy(REC.artist, "\"Perry, Katy\"");

	strcpy(REC.albumTitle, "Witness");

	strcpy(REC.songTitle,"Chained to the Rhythm");

	strcpy(REC.genre, "pop");

	REC.songLength.minutes = 4;

	REC.songLength.seconds = 36;

	REC.timesPlayed = -1;

	REC.rating = 6;



	// CALL INSETINFRONT FUCNTION

}
void deleteNodeT() {

	Node* pTemp = NULL;
	char text[100];

	printf("What is the name of the song you want to delete?\n");

	strcpy(text, "Chained to the Rhythm");

	int count = 0;
	if (strcmp(pTemp->info.songTitle, text) == 0) {
		pTemp->next->previous = NULL;
		pTemp = pTemp->next;
		free(pTemp);

	}
	else {

		while (strcmp(pTemp->info.songTitle, text) != 0) {
			pTemp = pTemp->next;

		}

		if (pTemp != NULL) {
			if (pTemp->next != NULL) pTemp->next->previous = pTemp->previous;
			if (pTemp->previous != NULL && pTemp->next != NULL) {
				pTemp->previous->next = pTemp->previous;
			}
			else if (pTemp->previous != NULL && pTemp->next == NULL) {
				pTemp->previous->next = NULL;
			}


			free(pTemp);
		}


	}

	//Function should delete the single node leaving the linkedlist as NULL
}
void shuffleT() {
	Node* temp = NULL;
	int order[1000];
	order[0] = 3;
	order[1] = 1;
	order[2] = 2;
	srand(time(0));
	int count = 3;
	

	while (temp->previous != NULL) temp = temp->previous;

	for (int m = 0; m < count; m++) {
		printf("%d, ", order[m]);
	}
	printf("\n");
	for (int k = 0; k < count; k++) {
		for (int l = 0; l < order[k] - 1; l++) {
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