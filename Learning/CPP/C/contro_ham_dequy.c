/*
buổi 1: làm quen qui tắt để chạy chương trình c
    chương trình c bao gồm:
        1. Header của chương trình ( thư viện, tiền xử lý).
        2. Hàm main trong chương trình.
        3. Biến và hàm.
        4. Những phần c bỏ qua không biên dịch -> comment  dành giao tiếp giữa lập trình viên.
Buổi 2: Hằng và biến
buổi 3: Đặc sản
        con trỏ -> truyền tham chiếu và truyền tham trị
        đệ quy
*/
#include <stdio.h>

/// doi hai so nguyen
void swap (int &a, int &b)
{
    printf("truoc khi thuc thi bieu thuc\n");
    printf ("swap - gia tri cua a: %d\n",a);
    printf(" swap - gia tri cua bien b: %d\n",b);
    //Swap hai bien int a va b
    a =a+b;
    b=a-b;
    a=a-b;
    printf("truoc khi thuc thi bieu thuc\n");
    printf ("swap - gia tri cua a: %d\n",a);
    printf(" swap - gia tri cua bien b: %d\n",b);
}

int main(void)
{
//    //Con trỏ
//    //con trỏ cũng là biến như bao biến khác / nó cấp phát bộ nhớ nhỏ hơn biến = biến cùng kiểu.
   
//    int a =5;
//    printf("Gia tri cua bien  a: %d\n",a);   
//    printf("Dia chi cua bien  a: %d\n",&a);  
//    int *x = &a;
//    printf("Gia tri cua bien  a: %d\n",*x);
//    printf(" gia tri x  = dia chi cua a: %d\n",x);
//    printf("dia chi cua X: %d\n",&x);
//    //printf("Sao a: %d\n",**a);   

    // /* tham chiếu tham trị*/
    // int a = 5, b =10;
    // swap(a,b);
    // printf ("gia tri cua a: %d\n",a);
    // printf("gia tri cua bien b: %d\n",b);
    // /* tham chiếu tham chiếu*/
    // int a = 5, b =10;
    // swap(a,b);
    // printf ("gia tri cua a: %d\n",a);
    // printf("gia tri cua bien b: %d\n",b);

    // //sum
    // /*
    //     truyền tham trị -> đưa giá trị vào hàm hoặc biến khác nhưng không làm thay đổi giá trị của
    //     biến khi thực thi hàm.
    //     truyền tham chiếu -> đưa hình chiếu của biến đi -> nếu có thao tác thay đổi.
    //     biến được đưa hình chiếu đi thay đổi theo
    // */ 

}