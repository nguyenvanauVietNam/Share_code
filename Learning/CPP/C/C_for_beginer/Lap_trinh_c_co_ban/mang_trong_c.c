/*
Mảng là một tập hợp tuần tự các phần tử có cùng kiểu dữ liệu
và các phần tử được lưu trữ trong một dãy các ô nhớ liên tục trên bộ nhớ. Các phần tử của mảng được truy cập bằng cách sử dụng “chỉ số”.
Mảng có kích thước N sẽ có chỉ số từ 0 tới N – 1
mảng chia ra 2 loại cơ bản
 - Mảng động.
 - Mảng cố định.

*/
#include <stdio.h>

typedef struct HocSinh HocSinh
{
    int maso;
    char hoten[25];
    int gioitinh;
};
// Cấu trúc Node
typedef struct Node //Xay dung mot Node trong danh sach
{
    int Data; //Du lieu co kieu item
    Node *next; //Truong next la con tro, tro den 1 Node tiep theo
};
//List la mot danh sach cac Node
typedef Node *List;
int main (void)
{
    // Mảng cố định
    int a[10];//mảng số nguyên
    char b[10];// mảng ký tự
    HocSinh c[10];// mảng cấu trúc dữ liệu

}