#include <stdio.h>
#include <math.h>
/*
    Tính tổng các số
    Tính S(n) = 1 + ½ + 1/3 + … + 1/n

    Phân tích:
    tổng phân số : sẽ là số thực -> chọn kiểu float

 */

// cách giải của Thầy Khang
// #include<stdio.h>
// #include<conio.h>
// int main()
// {
// 	int i, n;
// 	float S;
// 	S = 0; i = 1;
// 	do
// 	{
// 		printf("\nNhap n: ");
// 		scanf("%d", &n);
// 		if(n < 1)
// 		{
// 			printf("\nN phai lon hon hoac bang 1. Xin nhap lai !");
// 		}
// 	}while(n < 1);
// 	while(i <= n)
// 	{
// 		S = S + 1.0 / i;  // phải nhớ là 1.0 / i
// 		i++;
// 	}
// 	printf("i = %d", i);
// 	printf("\nS = %f", S);
// 	printf("\nTong 1 + 1/2 + ... + 1/%d la %.2f: ",n, S);
// 	getch();
// 	return 0;
// }

//thông thường
/* 
    Lấy mẫu số là i
    cho vòng lặp chạy từ i đến n
    mỗi lần tăng i 1 đơn vị
*/
float  Normal_Sum_sn( int n)
{
    int i;
    float tong = 0;
    for( i =1;i<=n;i++)
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
    if( n ==1 )return (float)1/1;
    // hàm đệ quy
    return (float)1/n + recursive_Sum_sn(n-1);
}
// Áp dụng toán học -> tôi vẫn chưa tìm ra công thức


int main (void)
{
    int n =5;
    printf("tong chuoi so (tu 1/1 - 1/%d)thong thuong la : %f\n",n,Normal_Sum_sn(n));
    printf("tong chuoi so (tu 1/1 - 1/%d)de quy la : %f\n",n,recursive_Sum_sn(n));
    
}