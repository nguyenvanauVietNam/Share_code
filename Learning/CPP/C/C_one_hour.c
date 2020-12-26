#include <stdio.h>
#include<string.h>

int bien;// khai bao bien
//biến toàn cục
//biến cục bộ.

// Giới hạn sử dụng biến trong c
//được xác định bởi giới hạn của {} and từ nó trở xuống
//ví dụ

int bien_toan_cuc = 5;

void Print_10()
{
    int bien_cuc_bo =10;
   // printf( "bien cuc bo: %d \n bien toan cuc: %d",bien_cuc_bo, bien_toan_cuc);
    //    printf( "bien cuc bo: %d \n bien toan cuc: %d",5, 7);

}

/// trên của biến -> tức là nhiều biến
// Nhiều biến mà có cấu trúc -> cấu trúc dữ liệu.

void Print_People()
{
    //nguoi
    char  ten[] ="nguyen van au";
    int  tuoi;
    char  gt[] = "nam";
    tuoi =18;
    printf("ten: %s\n",ten);
    printf("tuoi:%d\n",tuoi);
    printf("gioi tinh: %s\n",gt);
}

// cấu trúc dữ liệu
struct People
{
    /* data */
    char ten[25];
    int tuoi =10;
    char gt[25];
};


int main()
{
    People p;
    strcpy(p.ten,"nguyen van au");
    p.tuoi = 19;
    strcpy(p.gt,"nam");
    printf("ten: %s\n",p.ten);
    printf("tuoi:%d\n",p.tuoi);
    printf("gioi tinh: %s\n",p.gt);
   // Print_People();
    return 0;
}
