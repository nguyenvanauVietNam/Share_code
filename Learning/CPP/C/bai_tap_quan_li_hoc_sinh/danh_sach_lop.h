#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define siso 20
typedef struct dslop
{
    /* data */
    char ma_hs[10]; //Lưu mã số học sinh ( duy nhất)
    char ten_hs[25]; //Họ và tên học sinh : Nguyen Van Au -> Nguyen_Van_Au
    char gioi_tinh[5]; // gioi tinh Nam -> Nam
    char chuc_vu [25];// chức vụ -> Lop truong -> Lop_truong
    char the_duc[5];// điểm thể dục
    char nghe[5]; // điểm nghề
    char ky_thuat[5];// điểm kỹ thuật.
    float toan;// điểm toán
    float ly;//điểm vật lý
    float hoa; // điểm hóa học
    float sinh; // điểm sinh học
    float tin;// điểm tin học
    float van;// điểm môn ngữ văn
    float su;// điểm môn sử
    float dia;//điểm môn địa lý
    float av;// điểm môn anh văn
    float diem_tb;// điểm tb môn trong đó. Toán, Ngữ văn x2
}danh_sach_lop;

//khai bao lop hoc
// cho lớp học bằng null
void   empty_dsLop(danh_sach_lop ds[])
{
    int i;
    for(i =0;i<siso;i++)
    {
        //mã học sinh
        strcpy(ds[i].ma_hs,"rong");
        //tên học sinh
        strcpy(ds[i].ten_hs,"rong");
        //giới tính học sinh
        strcpy(ds[i].gioi_tinh,"rong");
        //mã chức vụ
        strcpy(ds[i].chuc_vu,"Lop_vien");
        //mã thể dục
        strcpy(ds[i].the_duc,"rong");
        //mã nghề
        strcpy(ds[i].nghe,"rong");
        //mã kỹ thuật
        strcpy(ds[i].ky_thuat,"rong");
        //điểm toán
        ds[i].toan =0;
        //điểm lý
        ds[i].toan =0;
        //điểm hóa
        ds[i].hoa =0;
        //điểm sinh
        ds[i].ly =0;
        //điểm tin
        ds[i].tin =0;
        //điểm anh văn
        ds[i].av =0;
        //điểm văn
        ds[i].van =0;
        //điểm sử
        ds[i].su =0;
        //điểm địa
        ds[i].dia =0;
        ds[i].diem_tb =0;
    }
}
//hiển thị lớp trên mang hình
//Hiển thị theo tên tăng dần theo bảng chữ cái alphabet
void hienthi(danh_sach_lop ds[])
{
    int i;
    printf("\n\t------------Danh sach hoc sinh lop---------------");
    printf("\n.---------------.-------------------------.------------.-------------.");
    printf("\n|  Ma hoc sinh  |        Ho va ten        |  Gioi tinh  |   Chuc vu   |");
    printf("\n.---------------.-------------------------.------------.-------------.");
    for(i=0;i<siso;i++)
    {
        printf("\n|%15s|%25s|%12s|%13s|",ds[i].ma_hs,ds[i].ten_hs,ds[i].gioi_tinh,ds[i].chuc_vu);
    }
    printf("\n.---------------.-------------------------.------------.-------------.");
}

//Sắp xếp lớp theo thứ tự tăng dần theo bảng chữ cái
// Đầu tiên: tách tên ra khỏi chuỗi họ và tên
// Sắp xếp tăng dần theo bảng chữ cái
//  tách tên ra khỏi chuỗi
// Split string = Chia chuỗi
void  Sap_xep_tang_dan(danh_sach_lop ds[])
{
    //dùng sắp xếp nổi bọt.
    int  i,j;
    //
    for (int i =0; i<siso;i++)
    {
        for( j=1;j<siso;j++)
        {
            //xử lý hàm trong
            // Tách tên ra khỏi chuổi họ tên
            char temp1[10]="";
            for(int k =strlen(ds[i].ten_hs);k>=0;k--)
            {   
               // if(ds[i].)
            }
            //So sánh tên
            //Đổi chỗ hai học sinh 
        }
    }

}




//tính điểm trung bình môn
float diem_tb (danh_sach_lop hs)
{
    float diem_tb;
    diem_tb = hs.toan*2 + hs.van *2 +hs.ly + hs.hoa+ hs.sinh + hs.dia + hs.su + hs.tin + hs.av;
    diem_tb = diem_tb/11;
    return diem_tb;
}


