#include "header.h"
 
void main() {
	Node* Head = NULL;
	Head = load(Head); // pre loads because if someone starts the program and chooses 2 it will delete evrything in the csv file
	while (1) {
		
		printf("What would you like to do?\n(1) load\n(2) store\n(3) display\n(4) insert\n(5) delete\n(6) edit\n(7) sort\n(8) rate\n(9) play\n(10) shuffle\n(11) exit");
		printf("\nType the number for the option you choose.\n");

		char artist[100];
		char artist2[100];
		int descisison = 0;
		char removeQ[100];
		scanf("%d", &descisison);

		switch (descisison) {

		case 1:
			// loads records
			system("cls");
			Head = load(Head);
			break;
		case 2:
			// stores records
			system("cls");
			store(Head);
			break;
		case 3:
			// dispalys records (all or form certain artists)
			printf("Would you like to choose a certain artist or dispaly all entrys? (type 1 for a certain artist) (type 2 for all entrys)\n");
			scanf("%d", &descisison);
			if (descisison == 1) {

				printf("Type the name of the artist as such: Example: \"Swift, Taylor\" or Eminem \n");

				clearBuffer();
				scanf("%99[^\n]", &artist);
				system("cls");
				display(Head, artist);
			}
			else {
				strcpy(artist, "none");
				system("cls");
				display(Head, artist);
			}
			break;
		case 4:
			system("cls");
			Head = insert(Head);
			break;
		case 5:
			system("cls");
			Head = deleteNode(Head);
			//printList(Head);;
			break;
		case 6:
			// allows you to edit entrys of a certain artist
			printf("Type the name of the artist as such: Example: \"Swift, Taylor\" or Eminem (notice how artists witha a first and last name use quotation marks)\n");

			clearBuffer();
			scanf("%99[^\n]", &artist);
			system("cls");
			edit(Head, artist);
			break;
		case 7:
			system("cls");
			int numb = 0;
			printf("Do you want to sort by (1) artist, (2) album title, (3) rating, (4) times played?\n (type the number of the option)\n");
			clearBuffer();
			scanf("%d", &numb);
			for (int i = 0; i < 4; i++) {
				Head = sort(Head, numb);
			}
			break;
		case 8:
			// allows you to change the rating of certain songs
			system("cls");
			rate(Head);
			break;
		case 9:
			// lets you choose a song and start playing the song in 5 second intervals
			system("cls");

			printList(Head);
			play(Head);
			break;
		case 10:
			system("cls");
			shuffle(Head);
			break;
		case 11:
			// stores and exits program
			store(Head);
			exit_();
			break;


		}
	}


}