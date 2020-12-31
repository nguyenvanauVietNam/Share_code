#include <stdio.h>

/*
Tính S(n) = ½ + ¼ + … + 1/2n
*/
//thông thường
/* 
    Lấy mẫu số là i =2
    cho vòng lặp chạy từ i đến 2n
    mỗi lần tăng i 2 đơn vị
*/
float  Normal_Sum_sn( int n)
{
    int i;
    float tong = 0;
    for( i =2;i<=n;i+=2)
    tong += (float)1.0/i;
    return tong;
}
//Giải theo đệ quy
/* 
    xác định điều kiện dừng

    n=1;
    xác định hàm đệ quy 1/n + đệ quy
    recursive = đệ quy
*/
float recursive_Sum_sn(int n)
{
    // điều kiện dừng của hàm
    if( n ==2 )return (float)1/2;
    // hàm đệ quy
    return (float)1/2*n + recursive_Sum_sn(n-2);
}
// Áp dụng toán học -> tôi vẫn chưa tìm ra công thức
int main(void)
{
    int n =6;
    
    printf("tong chuoi so (tu 1/2 - 1/2*%d)thong thuong la : %f\n",n,Normal_Sum_sn(n));
    printf("tong chuoi so (tu 1/2 - 1/2*%d)de quy la : %f\n",n,recursive_Sum_sn(n));
}