#include<stdio.h>
//thong thường
int Sum_n(int n)
{
    int tong = 0 ,i;
    for(i =1;i<=n;i++)
    tong+=i; // tong = tong +i;
    n=1;
    return tong;
}

//đệ quy

int de_quy_sum_n(int n)
{
    if(n==0)return 0;
    return (n + de_quy_sum_n(n-1));
}
//theo logic toán học của tôi
///1 +2 +3 +4 +5+6 //  (1+6)+(2+5)+(3+4)
///1 +2 +3 +4 +5 //  (1+4)+(2+3)+5
 int toanhoc_sum_n(int n)
 {
     int tong =0 ,i;
    if(n%2==0)
    {
        tong = (1+n) * (n/2);
    }
    else
    {
      tong = (n) * ((n-1)/2) + n;
    }
    
    return tong;
 }

//Theo toán học
/*
    Sn = 1 +2 +3 +..+n = n(n+1)/2

*/
int toan_hoc_sum_n_1(int n)
{
   
    return n*(n+1)/2;
}

int main(void)
{
    int  n =5;
    printf("tong gia tri tu 1 - %d la : %d\n",n,de_quy_sum_n(n));
    printf("tong gia tri tu 1 - %d la : %d\n",n,toan_hoc_sum_n_1(n));
}