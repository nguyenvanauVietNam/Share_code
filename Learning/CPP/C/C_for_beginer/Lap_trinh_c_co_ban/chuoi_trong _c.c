#include <stdio.h>
#include <string.h>

int main(void)

{
        char CHUOI_MAC_DINH[100] = "hello word!";
        char CHUOI[100];// khai báo chuỗi 100 ký tự
        fgets(CHUOI,sizeof(CHUOI),stdin);// nhập cả khoảng trắng
        printf("\nChuoi mac dinh: %s",CHUOI_MAC_DINH);
        printf("\n Chuoi nhap vao: %s", CHUOI);


}