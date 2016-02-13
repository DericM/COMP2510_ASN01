
/*
 * asn01_mccaddend.c
 *
 *    Created on: Feb 02, 2016
 *        Author: Mccadden, Deric
 * StudentNumber: A00751277
 */

#include <stdio.h>
#include <string.h>
#define LINESIZE 1024
#define CHECK(PRED) printf("%s ... %s\n",(PRED) ? "passed" : "FAILED", #PRED)

int get_words(const char prompt[], char word[], size_t n, const char eof[]);
int get_int(const char prompt[], int min, int max, int eof);
void print_menu();
void display_all();
void modify();
void append();


int main(int argc, char *argv[]) {
  
  FILE *fp;
  int choice;
  char prompt[] = "Input Choice:";
  char a;
  int stn;

  if((fp = fopen(argv[argc-1], "w")) == 0){
    perror("Failed to open file.");
    return 1;
  }

  while(1){
    choice = -3;
    print_menu();
    choice = get_int(prompt, -1, 100, -2);

    if(choice == -2)
      break;
    
    
    else if(choice == -1) {
      
      printf("A00000000\n");
      while(1){
        
        scanf("a", &a);
        
        
        scanf("8%d", &stn)
        
        if(a == 'a'){
          printf(" %c", a);
        }
        
        
        

      }
    }
    
    
    
    else if(choice == 0)
      ;
      /*display_all();*/
      
      
    else if(choice > 0)
      ;
      /*modify(choice);*/
      
      
      
    else {}
  }



  
  fclose(fp);

  return 0;
}









/*
 * 
 */
void squeeze_spaces (void) {
  int c;
  while ((c = getchar()) != EOF){
    if (c == ' '){
      while ((c = getchar()) == ' ')
        ;
      printf(" ");
    }
    putchar(c);
  }
}



/*
 * Prints a basic menu.
 */
void print_menu(){
  printf("--------Menu--------\n");
  printf("Quit------------(-2)\n");
  printf("Append----------(-1)\n");
  printf("Display-All-----( 0)\n");
  printf("Modify-Record-n-( n)\n");
}


void display_all(){

}

void modify(){

}



/*
void append(FILE *fp){
  char prompt[] = "Input Choice:";
  char stn[20];


  get_stn(&fp, &stn);

  fprintf(fp, "stuff\n");

}
*/







/* returns 1 if a word is succesfuly read and stored in the array of n characters
 * otherwise returns 0 on end of file or when the user inputs the word specified
 * by eof 
 */
int get_words (const char prompt[], char word[], size_t n, const char eof[]) {
  char line[LINESIZE];

  while(1){
    memset(word,0,n);
    printf("%s\n", prompt);
    if(!fgets(line, LINESIZE, stdin)){
      clearerr(stdin);
      break;
    }
    if(sscanf(line, "%s", word) == 1){
      /* check for eof*/
      if(!strcmp(word, eof)){
        break;
      }
      /* check for length */ 
      if (strlen(word) < n)
        return 1;
    }
  }
  return 0;
}


/* if an interger between min and max inclusive is sucessfuly read, it is 
 * returned; otherwise, the integer eof is returned when the user enters it on
 * the end-of-file
 * precondition: (min <= max) && (eof < min || eof > max)  
 */
int get_int(const char prompt[], int min, int max, int eof) {
  char line[LINESIZE];
  int n;
  while(1){
    printf("%s\n", prompt);
    if(!fgets(line, LINESIZE, stdin)){
      clearerr(stdin);
      break;
    }
    if (sscanf(line, "%d", &n) == 1){
      if(min <= n && n <= max){
        return n;
      } else {
        break;
      }
    }
  }
  return eof;
}

