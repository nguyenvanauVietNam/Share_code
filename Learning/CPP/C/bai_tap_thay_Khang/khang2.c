#include <stdio.h>
#include <math.h>

//thông thường

int Sum_sn(int n)
{
    int i,tong=0;
    // không nên để i = 0  vì có thể dính đến 0^2
    for(i =1;i<=n; i++)
    {
        tong += (int)pow(i,2); // tương đương tong = tong + pow(i,2) tức là i mũ 2
    }
    return tong;
}
//đệ quy
int dq_sum_sn(int n)
{
    if( n ==1 )return n*n;
    return  ( n*n+ dq_sum_sn(n-1));
}

//toán học
/*
    Sn = 1^2 + 2^2 + 3^2 + ... +n^2 = n*(n+1)*(2*n+1)/6

*/
int th_sum_sn(int n)
{
    return n*(n+1)*(2*n+1)/6;
}

//thầy giải

int sum_sn(int n)
{
    int i,tong=0;
    // không nên để i = 0  vì có thể dính đến 0^2
    for(i =1;i<=n; i++)
    {
        tong += i*i; // i^2 = i*i
    }
    return tong;
}
int main (void)
{
    int n =5; // 1^2 = 1 ; 2^2 = 4 ; 3^2 = 9; 4^2 =16 ; 5^2 =25

    printf("tong gia tri tu 1^2 - %d^2  tt la : %d\n",n,(int)Sum_sn(n));
    printf("tong gia tri tu 1^2 - %d^2  dq la : %d\n",n,dq_sum_sn(n));
    printf("tong gia tri tu 1^2 - %d^2  th la : %d\n",n,th_sum_sn(n));
    printf("tong gia tri tu 1^2 - %d^2  thay la : %d\n",n,sum_sn(n));
}