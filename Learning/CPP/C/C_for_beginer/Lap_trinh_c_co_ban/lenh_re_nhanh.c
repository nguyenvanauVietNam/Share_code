#include <stdio.h>
/*
    Cấu trúc điều khiển & rẽ nhánh
    - Cấu trúc điều khiển if else
        Cấu trúc if không else
        Cấu trúc if... else
        Cấu trúc muilti if.. else
    - Vòng lặp
        Vòng lặp for
        Vòng lặp while
        Vòng lặp do while
    - Cấu trúc điều khiển switch case
    - Lệnh break, continue, retrun , exit
*/
// Cấu trúc if không else
void kiem_tra_so_am_duong(int a)
{
    if(a>0) printf("\n %d la so duong",a);
    if(a<0) printf("\n %d la so am",a);
    if(a==0) printf("\n %d la so khong am khong duong",a);
}

//  Cấu trúc muilti if.. else
void kiem_tra_so_am_duong_if_else(int a)
{
    if(a>0) printf("\n %d la so duong",a);
    else if(a==0) printf("\n%d la so khong am khong duong",a);
    else printf("\n %d la so am",a);
}
//  Cấu trúc if... else
void kiem_tra_so_chia_het_cho_2(int a)
{
    if(a%2==0) printf("\n %d la so chia  het cho 2",a);
    else printf("\n%d khong chia het cho 2",a);
    
}
//Cấu trúc điều khiển switch case
void Kiem_tra_so_ngay_trong_nam_khong_nhuan(int a)
{
    switch (a)
    {
    case 1:
        /* code */
        printf("\n thang %d co : 31 ngay",a);
        break;
    case 2:
        /* code */
        printf("\n thang %d co : 28 ngay",a);
        break;
    case 3:
        /* code */
        printf("\n thang %d co : 31 ngay",a);
        break;
    case 4:
        /* code */
        printf("\n thang %d co : 30 ngay",a);
        break;
    case 5:
        /* code */
        printf("\n thang %d co : 31 ngay",a);
        break;
    case 6:
        /* code */
        printf("\n thang %d co : 30 ngay",a);
        break;
    case 7:
        /* code */
        printf("\n thang %d co : 31 ngay",a);
        break;
    case 8:
        /* code */
        printf("\n thang %d co : 31 ngay",a);
        break;
    case 9:
        /* code */
        printf("\n thang %d co : 30 ngay",a);
        break;
    case 10:
        /* code */
        printf("\n thang %d co : 31 ngay",a);
        break;
    case 11:
        /* code */
        printf("\n thang %d co : 30 ngay",a);
        break;
    case 12:
        /* code */
        printf("\n thang %d co : 31 ngay",a);
        break;
    
    default:
        printf("\n so %d khong thuoc thang trong nam",a);
        break;
    }
}

// Vòng lặp vào lệnh break, continue, exit,return
//lệnh trả về return -> được sử dụng như lệnh thoát hàm hay trả về giá trị sau khi thực
// thi hàm
// ex 1 trả về sau khi thực hiện ham
int dien_tich_hinh_chu_nhat(int a, int b)
{
    return a*b;// return giá trị diện tích
}
// ex 2 trả về với vai trò là thoát hàm
// hàm trả về giá trị a nếu nó là số nguyên tố = 0 nếu nó không phải số nguyên tốt
int kiem_tra_so_nguyen_to(int a)
{
    int i;
    for(i=2;i<=a/2;i++)
    {
        if (a%i==0)
        {
           // printf("\n%d khong la so nguyen to",a);
            return 0;// tức a không phải số nguyên tố
        }
    }
  //  printf("\n%d  la so nguyen to",a);
    return a;
}

//lệnh break, break là lệnh dừng vòng lặp -> while
void kiem_tra_so_nguyen_to_a(int a)
{
    if( a==5||a==7)  printf("\n%d la so nguyen to",a);
    int i=3, k=0;
    while(i>a/2)
    {
        if (a%i==0)
        {
           k = 1;
           break;// thoát chương trình vì không cần kiểm tra bất cứ gì thêm
        }
        i++;
    }
    if(k==0)printf("\n%d la so nguyen to",a);
    else printf("\n%d khong la so nguyen to",a);

}
// lệnh exit được giới thiệu trong phần đọc ghi file
// lệnh continue -> dùng để bỏ qua một số lệnh trong vòng lặp
// hàm kiểm tra xem từ 1 đến n có bao nhiêu số nguyên tố
//điều kiện n >0;
int kiem_tra_so_nguyen_to_tu_1_n(int n)
{
    int k=1;
    if(kiem_tra_so_nguyen_to(n)!= 0)k++;
    do
    {
        /* code */
          n--;
        if( kiem_tra_so_nguyen_to(n)!= 0)
        {
            // nếu n==0 tức là không phải là số nguyên tố nên ta bỏ qua
            k++;
            n--;
            continue;
        }
    } while (n>0);
    return k;
}
int main(void)
{
    int so =11;
    scanf("%d",&so);
    kiem_tra_so_am_duong(so);
    kiem_tra_so_am_duong_if_else(so);
    kiem_tra_so_chia_het_cho_2(so);
    Kiem_tra_so_ngay_trong_nam_khong_nhuan(so);
    printf("\nTrang thai:%d",kiem_tra_so_nguyen_to(so));
    kiem_tra_so_nguyen_to_a(so);
    printf("\ntu 1 den %d co : %d so nguyen to",so,kiem_tra_so_nguyen_to_tu_1_n(so));
}