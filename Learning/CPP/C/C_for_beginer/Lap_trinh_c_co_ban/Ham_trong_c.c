#include <stdio.h>
// Hàm trong c
/*
Hàm (Function) trong C++ là tập hợp nhiều câu lệnh để thực hiện một chức năng cụ thể nào đó.
Hàm có thể được gọi lại ở nhiều nơi khác nhau trong chương trình.
Có 2 loại hàm cơ bản
- Hàm có giá trị trả về.
- Hàm không có giá trị trả về.
Có 2 cách truyền hàm
- Truyền hàm giá trị đầu vào
    + Truyền tham chiếu
    + Truyền tham trị
- Không truyền giá trị đầu vào
*/
// hàm in trả về vô kiểu - Hàm không truyền đầu vào
void In_1_den_10()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("\nI:%d",i);
    }
}
// hàm trả về giá trị - Hàm truyền tham trị
int tong_a_b(int a, int b)
{
    return a+b;
}
// hàm không có giá trị trả về - truyền tham trị
void SWAP_A_B( int *a, int *b)
{
    *a = *a +*b;
    *b= *a-*b;
    *a=*a-*b;
}
int main()
{
    int a=5, b=7;
    In_1_den_10();
    printf("\n Tong cua %d, %d la: %d",a,b,tong_a_b(a,b));
    SWAP_A_B(&a,&b);
    printf( "\nKet qua sau khi SWAP A: %d, B: %d",a,b);
}