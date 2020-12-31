#include "danh_sach_lop.h"

//hàm đọc file  -> lấy thông tin lớp từ file
void doc_file()
{
    char c[1000];
    FILE *fptr;
 
    if ((fptr = fopen("bang_diem_lop.in", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
 
    // reads text until newline 
    fscanf(fptr,"%[^\n]", c);
 
    printf("Data from the file:\n%s", c);
    fclose(fptr);
}




void ghi_file()
{
   FILE *fptr;
   //hàm mở file :
   /*
    a* : đọc và ghi ở cuối file
    r+, w+ cho phép đọc và ghi
    r: chỉ cho phép đọc.
    w: chỉ cho phép ghi.

  */
    fptr = fopen("danh_sach_lop.in","r");
 // nếu đoc không được file thì trả về giá trị
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
 
 //hàm fprintf ghi file
 //  fprintf(fptr,"%d",num);
   fclose(fptr);
}