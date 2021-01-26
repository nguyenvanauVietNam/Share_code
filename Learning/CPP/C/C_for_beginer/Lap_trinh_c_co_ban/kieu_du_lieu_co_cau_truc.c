#include <stdio.h>
//cấu trúc dữ liệu

typedef struct SinhVien
{
    /* data */
    int maso;
    char ten[25];
    int gioi_tinh;
}SinhVien;

int main()
{
    SinhVien sv;
    printf("\n Nhap vao ma sinh vien");
    printf("\nmaso:");scanf("%d",&sv.maso);
    printf("\n Nhap vao ho ten sinh vien");
    fflush(stdin);
    gets(sv.ten);
    printf("\ngioi tinh:");scanf("%d",&sv.gioi_tinh);


    printf("\nNhun gi vua nhap\n");
    printf("\nMa so sinh vien: %d",sv.maso);
    printf("\nHo va ten: %s",sv.ten);
    printf("\nGioi tinh : %d",sv.gioi_tinh);
}