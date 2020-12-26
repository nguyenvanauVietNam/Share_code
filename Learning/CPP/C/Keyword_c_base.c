#include <stdio.h>
// Các từ khóa trong c
//Làm thế nào để tránh việc đặt trùng tên.

void selected_print(int x)
{
    switch (x)
    {
    case 1/* constant-expression */:
        /* code */
        printf("You Input enter one \n");
        break;
    case 2/* constant-expression */:
        /* code */
        printf("You Input enter two \n");
        break;
    default:
        printf("Hello c! \n");
        break;
    }
}


int main (void)
{
    // int  tuoi ;// truyền số nguyên Interger
    // char maSV[10]; // truyền vào mảng ký tự char
   // auto maSV = "b1400745";
   // auto tuoi = 10;
   // printf("maSV : %s \n",maSV);
    //printf("tuoi : %d \n",tuoi);

    /* 
         từ khóa : if else auto sizeof()
         if else ( có else là phải có if)
         có if có thể không else
    */
   /*
    auto temp = "nguyen van au";
    printf("size of temp : %d\n",sizeof(temp));
    if(sizeof(temp) == 4)
    {
        printf ("Bien tam co the la kieu Int");
    }
   // else {printf ("Bien tam co the la kieu khac");}
*/

    // Ôn lại :
    // switch case default break
 
    /*
    int x ;
    scanf("%d",&x);
    selected_print(x);
    */

   
}