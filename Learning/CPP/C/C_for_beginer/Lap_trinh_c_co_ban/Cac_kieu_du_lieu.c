#include <stdio.h>
/* 
    Data type ( Kiểu dữ liệu)
    - Primitive type  ( Kiểu dữ liệu nguyên thủy)
        + Kiểu ký tự ( char)
        + Kiểu số nguyên (int)
        + Kiểu số thực (float)
        + Kiểu void     (void)
    - Derived type (Kiểu dữ liệu có nguồn gốc)
        + Signed
        + Unsigned
    - User defined type (Kiểu dữ liệu người dùng tự định danh)
        + struct
        + Union
        + Enum

    - Kiểu dữ liệu      Kích thước    
      char	            1 byte	
      unsigned char	    1 byte	
      signed char	    1 byte	
      int	            2 or 4 bytes
      unsigned int	    2 or 4 bytes	
      short	            2 bytes	
      unsigned short	2 bytes	
      long	            8 bytes
      unsigned long	    8 bytes
      float	            4 byte		6 chữ số thập phân
      double	        8 byte		15 chữ số thập phân
      long double	    10 byte     19 chữ số thập phân

*/
int main(void)
{
    int INT =10;
    signed int SIGNED_INT;
    unsigned int UNSIGNED_INT;
    short int SHORT_INT;
    long int LONG_INT;
    float FLOAT =5.5;
    char CHAR ='c';
    unsigned char UNSIGNED_CHAR;

    //size of data types
    printf("Size of int is %d\n", sizeof INT);
    printf("Size of unsigned int is %d\n", sizeof UNSIGNED_INT);
    printf("Size of signed int is %d\n", sizeof SIGNED_INT);
    printf("Size of short int is %d\n", sizeof SHORT_INT);
    printf("Size of long int is %d\n", sizeof LONG_INT);
    printf("Size of float is %d\n", sizeof FLOAT);
    printf("Size of char is %d\n", sizeof CHAR);
    printf("Size of unsigned char is %d\n", sizeof UNSIGNED_CHAR);
}