#include <stdio.h>
#include <conio.h>

int main(void)
{
    // int interger; // lưu trữ kiểu số nguyên.
    // char charater; //lưu trữ ký tự.
    // char multi_char [100]; //lưu trữ chuổi ký tự.
    // printf("bien:");
    // scanf("%d",&interger);
    //  fflush(stdin);
    //  printf("\nky tu:");
    // scanf("%c",&charater);
    //  fflush(stdin);//lưu ý đọc \n
    //  printf("\nchuoi:");
    // gets(multi_char);
    //  fflush(stdin);



    // printf("bien: %d\n",interger);
    // printf("ky tu: %c\n",charater);
    // printf("chuoi: %s\n",multi_char);
    const int namsinh =1996; // hằng là giá trị không thay đổi

    int  i =0,tong =0;
    for(;i<=10;i++)
    {
        tong +=i;
       
    }
    printf("tong cac so tu 0 den 10 la: %d",tong);
     printf("nam sinh la: %d",namsinh);
}
