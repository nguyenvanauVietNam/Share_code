#include <stdio.h>

/*
Tính T(n) = 1 x 2 x 3…x n
*/
//thông thường
/* 
    Lấy mẫu số là i =1
    cho vòng lặp chạy từ i đến 2n
    mỗi lần tăng i 1 đơn vị
*/
long  Normal_Sum_sn( int n)
{
    int i;
    long tich = 1;
    for( i =1;i<=n;i++)
    tich *=i;
    return tich;
}
//Giải theo đệ quy
/* 
    xác định điều kiện dừng

    n=1;
    xác định hàm đệ quy 1/n + đệ quy
    recursive = đệ quy
*/

// tính bằng toán học  -> bài toán rất giống với n!
long recursive_Sum_sn(int n)
{
    // điều kiện dừng của hàm
    if( n ==1 )return 1;
    // hàm đệ quy
    return n * recursive_Sum_sn(n-1);
}
// Áp dụng toán học -> tôi vẫn chưa tìm ra công thức
int main(void)
{
    int n =6;
    
    printf("tich chuoi so (tu 1 - 1/2*%d)thong thuong la : %d\n",n,Normal_Sum_sn(n));
    printf("tich chuoi so (tu 1/2 - 1/2*%d)de quy la : %d\n",n,recursive_Sum_sn(n));
}