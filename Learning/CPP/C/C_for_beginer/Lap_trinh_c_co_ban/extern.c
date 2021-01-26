/*
    Trao đổi dữ liệu trong c gồm có
    - Trao đổi giữa các file : Đọc ghi file
    - Trao đổi trực tiếp. bằng biến mở rộng - extern
*/
#include <stdio.h>
extern int DOI_BIEN;
extern int tinh_tong(int a, int b);
int main(void)
{

    printf("tong: %d",tinh_tong(10,DOI_BIEN));
}