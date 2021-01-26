#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
int main(void)
{
    //ghi 1 câu văn bản
   char sentence[1000];
   FILE *fptr;
 
   fptr = fopen("ghi_van_ban.txt", "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   
   printf("\nNhap van ban:\n");
   gets(sentence);
 
   fprintf(fptr,"%s", sentence);
   fclose(fptr);
   // Ghi câu văn bản
    if ((fptr = fopen("ghi_van_ban.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
    char c[1000];
    // reads text until newline 
    fscanf(fptr,"%[^\n]", c);
 
    printf("\nDu lieu trong file:\n%s", c);
    fclose(fptr);
 

  
}
 