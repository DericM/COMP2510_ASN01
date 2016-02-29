
/*
* asn01_mccaddend.c
*
*    Created on: Feb 02, 2016
*        Author: Mccadden, Deric
* StudentNumber: A00751277
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LINESIZE 1024
#define CHECK(PRED) printf("%s ... %s\n",(PRED) ? "passed" : "FAILED", #PRED)

int get_words(const char prompt[], char word[], size_t n, const char eof[]);
int get_int(const char prompt[], int min, int max, int eof);
void print_menu();

int main(int argc, char *argv[]) {

	print_menu();

	int c;




	printf("");
	while (1) {
		make_choics(get_choice());
	}




	/*
	int c;
	while ((c = getchar()) != EOF)
		;

	FILE *fp = "file.txt";
	int c;
	while ((c = fgetc(fp)) != EOF)
		;

	char line[LINESIZE];
	while (fgets(line, LINESIZE, stdin))
		;
	*/
	return 0;
}


/* 
prints a simple menu
*/
void print_menu() {
	printf("--------Menu--------\n");
	printf("Quit------------(-2)\n");
	printf("Append----------(-1)\n");
	printf("Display-All-----( 0)\n");
	printf("Modify-Record-n-( n)\n\n");
}

/*
Return 1 if a valid choice has been made, if not return 0;
*/
int make_choics(int choice) {
	if (choice == -2)
		exit(1);
	else if(choice == -1)
		append();
	else if (choice == 0)
		display_all();
	else if (choice >= 1)
		modify();
	else
		return 0;
	return 1;
}


int get_choice() {
	int c;
	while ((c = getchar()) != EOF)
		return c;

	c = getchar();

	return -2;
}