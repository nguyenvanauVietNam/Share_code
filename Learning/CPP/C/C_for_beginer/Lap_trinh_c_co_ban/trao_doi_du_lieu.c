/*
    Trao đổi dữ liệu trong c gồm có
    - Trao đổi giữa các file : Đọc ghi file
    - Trao đổi trực tiếp. bằng biến mở rộng - extern
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // ghi file
    int num;
   FILE *fptr;
   fptr = fopen("trao_doi_du_lieu.txt","w");
 
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
 
   printf("\nnhap vao : ");
   scanf("%d",&num);
 
   fprintf(fptr,"%d",num);
   fclose(fptr);

    // đọc file
   if ((fptr = fopen("trao_doi_du_lieu.txt","r")) == NULL){
       printf("Error! opening file");
 
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
 
   fscanf(fptr,"%d", &num);
 
   printf("Value of n=%d", num);
   fclose(fptr); 
}