/* 
File:	McCroneBrody_A00846163.c 
Author: Brody McCrone
Date:	2016/02/12
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LINESIZE 1024

int get_selection();
void displaySelection();
void call_selection(FILE *fp, int selection);
void quit(FILE *fp);
void append(FILE *fp);
void display(FILE *fp);
void modify(FILE *fp, int record);
int get_id(char entry[]);
int get_grade();
void new_record(FILE *fp);

int main(int argc, char *argv[]) {
   FILE *fp; 
   if (argc != 2) { 
      perror("usage: %s {spource-file} {destination-file}\n");
      exit(1);
   }
   
   if ((fp = fopen(argv[1], "w+b")) == 0) {
      perror("failed to open file");
      exit(1);
   }
   
   while(1) {
      displaySelection();
      call_selection(fp, get_selection());
   }
   return 0;
}

void displaySelection() {
   printf("-2\tquit\n");
   printf("-1\tappend a recordord\n");
   printf("0\tdisplay all recordords\n");
   printf("n)\tmodify a recordord\n");
}

int get_selection(FILE *fp) {
   char line[LINESIZE];
   int selection = -4;
   while(selection <= -3) {
      printf("Enter Selection:\n");
      if(!fgets(line, LINESIZE, stdin)) {
         clearerr(stdin);
      }
      sscanf(line, "%d", &selection);
      if(feof(stdin)) {
         clearerr(stdin);
         quit(fp);
      }
   }
   return selection;
}

void call_selection(FILE *fp, int selection) {
   switch(selection) {
   case -2:
      quit(fp);
      break;
   case -1:
      append(fp);
      break;
   case 0: 
      display(fp);
      break;
   default:
      modify(fp, selection);
   }
}

void quit(FILE *fp) {
   if(fclose(fp) == EOF) {
      perror("fclose");
   }
   exit(1);
}

void append(FILE *fp) {
   fseek(fp, 0, SEEK_END);
   new_record(fp);
}

void modify(FILE *fp, int record) {
   int num_recs = 0;
   char line[LINESIZE];
   char line2[LINESIZE];
   char line3[LINESIZE];
   int grade = 0;
   fseek(fp, 0, SEEK_SET);
   while(fgets(line3, LINESIZE, fp)) {
      num_recs++;
   }
   clearerr(stdin);
   if(record > num_recs) {
      printf("that recordord does not exist");
      return;
   }
   fseek(fp, 14 * (record - 1), SEEK_SET);
   if(!fgets(line, LINESIZE, fp)) {
      clearerr(stdin);
   }
   sscanf(line, "%s %d", line2, &grade); 
   fprintf(stderr, "%d %s %d\n", record, line2, grade);
   fseek(fp, 14 * (record - 1), SEEK_SET);
   new_record(fp);
}

void new_record(FILE *fp) {
   char entry[LINESIZE];
   int  n;
   if(!get_id(entry)) {
      return;
   }
   n = get_grade();
   if(n == -1) {
      return;
   }
   if(n <= 10) {
      fprintf(fp, "%s   %d\n", entry, n);
   } else if (n != 100) {
      fprintf(fp, "%s  %d\n", entry, n);
   } else {
      fprintf(fp, "%s %d\n", entry, n);
   }
}

int get_id(char entry[]) {
   int    numerical;
   char   line[LINESIZE];
   int test = 0;
   size_t lineLength = 1;
   size_t i;
   while(lineLength != 9 || (entry[0] != 'a' && entry[0] != 'A') || !numerical) {
      numerical = 1;
      printf("Enter StdID:\n");
      if (fgets(line, LINESIZE, stdin) != NULL) {
         sscanf(line, "%d", &test);
         if(feof(stdin) || test == -1) {
            clearerr(stdin);
            return 0;
         }
         if(sscanf(line, "%s", entry)) {
            lineLength = strlen(entry);
            for(i = 1; i < 9; i++) {
               if(!isdigit((int)entry[i])) {
                  numerical = 0;
               }
            }
         }
      }
   }
   return 1;
}

int get_grade() {
   char line[LINESIZE];
   int n = -2;
   while(n <= -1 || n >= 100) {
      if (n == -1) {
         return -1;
      }
      printf("Enter Grade:\n");
      if(fgets(line, LINESIZE, stdin) != NULL) {
         if(feof(stdin)) {
            clearerr(stdin);
            return -1;
         }
         sscanf(line, "%d", &n);
      }
   }
   return n;
}

void display(FILE *fp) {
   char line[LINESIZE];
   char stdId[9];
   int grade = 0;
   int n = 1;
   fflush(fp);
   fseek(fp, 0, SEEK_SET);
   while((fgets(line, LINESIZE, fp)) != NULL) {
      if(sscanf(line, "%s %d", stdId, &grade)) {
         fprintf(stderr, "%d %s %d\n", n++ , stdId, grade);
      }
   }
   fflush(stdout);
}










