/*
    Con trỏ trong C cũng chỉ là là biến, cũng có thể khai báo,
        khởi tạo và lưu trữ giá trị và có địa chỉ của riêng nó.
    Nhưng biến con trỏ không lưu giá trị bình thường, nó là biến trỏ tới 1 địa chỉ khác,
        tức mang giá trị là 1 địa chỉ.
    - Cách khai báo: <kiểu dữ liệu> * <tên biến>
        int *p_i; // khai báo con trỏ để trỏ tới biến kiểu nguyên
        int *p, val; // khai báo con trỏ p kiểu int, biến val (không phải con trỏ) kiểu int
        float *p_f; // khai báo con trỏ để trỏ tới biến kiểu thực
        char *p_char; // khai báo con trỏ để trỏ tới biến kiểu ký tự
        void *p_v; // con trỏ kiểu void (không kiểu)
*/
#include <stdio.h>
int main(void)
{
    int number = 5;
    int *p_int = &number;
    printf ("\n p_int: %d",p_int);
    printf ("\n *p_int: %d",*p_int);
    printf ("\n &p_int: %d",&p_int);
}