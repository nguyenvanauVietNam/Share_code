//#include <stdio.h>
/*
phần header này chính là tập hợp các lệnh được ghi 1 file nào đó, mà ta import lai trong chương trình
1. Thư viện (header) có sẵn.
2. Chính bản thân người lập trình tạo ra.
*/

// có thể thêm thư viện mình tự làm ra

//quy tắc thực hiện trên c là chương trình chạy từ trên xuống
//tức là chạy từ dòng 1 -> end (dòng cuối cùng)

/*
    một chương trình c bao gồm:
    1> Header của chương trình.
    2> hàm chính [ Hàm main ()].
    3> Các hàm phụ và biến phụ.
    4> Các comment.

    Quy tắc của c.
    Chương trình c được thao tác từ trên xuống.

*/
#include "helloword.h" //1
int main (void) //2
{

    int a, b; //3biến số

    Helloword();
   //printf("Hello c!");
    
}
/*
int main(int argc, char* argv[])
{
    int i ;
    for ( i = 0; i < argc; i++)
    {
        // code 
        printf("%s",argv[i]);
    }
    
    printf("\n");
    return 0;
}

*/
