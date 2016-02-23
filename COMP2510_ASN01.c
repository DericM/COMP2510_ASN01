
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
#define LINESIZE 1024
#define CHECK(PRED) printf("%s ... %s\n",(PRED) ? "passed" : "FAILED", #PRED)

int get_words(const char prompt[], char word[], size_t n, const char eof[]);
int get_int(const char prompt[], int min, int max, int eof);
void print_menu();

int main(int argc, char *argv[]) {







	return 0;
}


/* prints a simple menu
*/
void print_menu() {
	printf("--------Menu--------\n");
	printf("Quit------------(-2)\n");
	printf("Append----------(-1)\n");
	printf("Display-All-----( 0)\n");
	printf("Modify-Record-n-( n)\n\n");
}


