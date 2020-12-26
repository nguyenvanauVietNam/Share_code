#include <stdio.h>
#include<limits.h> // for int,char macros 
#include<float.h> // for float,double macros 
 
 // Input sizeof var
 //Outphut Type of var
/*
    Hàm nhận vào kích thước của biến
    Sau đó trả về kiểu dữ liệu của biến
*/

const char * detected_type_in_c(int x ) {
   if( x== 1) return " Type is Char";
   if( x== 1) return " Type is Boolean";
   if( x== 4) return " Type is Interger";
   if( x== 4) return " Type is Floar";
   if( x== 8) return " Type is Double";
   if( x== 2) return " Type is Short Int";
   if( x== 8) return " Type is Short Long Double";
   return "Undefine";
}