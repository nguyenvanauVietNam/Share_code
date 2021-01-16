/*
 Các toán tử trong c
 - Toán tử số học (Arithmetic Operators).
    +	phép toán cộng
    –	phép toán trừ
    *	phép toán nhân
    /  	phép toán chia
    %	phép toán lấy số dư(chỉ áp dụng cho số nguyên)
 - Toán tử tăng, giảm (Increment and Decrement).
    ++  Tăng giá trị lên 1 đơn vị
    --  Giảm giá trị đi 1 đơn vị
 - Toán tử gán (Assignment Operators).
    Toán tử     Rút gọn     Đầy đủ
    =	        a = b	    a = b
    +=	        a += b	    a = a+b
    -=	        a -= b	    a = a-b
    *=	        a *= b	    a = a*b
    /=	        a /= b	    a = a/b
    %=	        a %= b	    a = a%b
 - Toán tử quan hệ (Relational Operators).
    Toán tử     Ý nghĩa
    ==	        so sánh bằng	
    >	        so sánh lớn hơn	
    <	        so sánh nhỏ hơn	
    !=	        so sánh khác	
    >=	        lớn hơn hoặc bằng	
    <=	        nhỏ hơn hoặc bằng
 - Toán tử logic (Logical Operators).
    Toán tử     Cách đọc    Ý Nghĩa
    &&          AND         trả về true khi và chỉ khi tất cả các toán hạng đều đúng.
    ||          OR          trả về true khi có ít nhất 1 toán hạng đúng.
    !           NOT         phủ định giá trị của toán hạng.
 - Toán tử bit (Bitwise Operators).
    Toán tử     Ý nghĩa
    &	        Bitwise AND
    |	        Bitwise OR
    ^	        Bitwise exclusive OR
    ~	        Bitwise complement
    <<	        Shift left
    >>	        Shift right
 - Toán tử “phảy” (Comma Operator).
 - Toán tử sizeof (sizeof Operator).
*/
#include <stdio.h>

int main(void)
{
    //Toán tử “phảy” (Comma Operator).
    int a =12,b=25,c;
    //Toán tử sizeof (sizeof Operator).
    int z = sizeof(a);// gán giá trị sizeof(a) cho z
    //Toán tử bit (Bitwise Operators).
        //Bitwise AND
    /*
        12 = 00001100 (In Binary)
        25 = 00011001 (In Binary)

        Bit Operation of 12 and 25
            00001100
          & 00011001
            ________
            00001000  = 8 (In decimal)
    */
    printf("\n Bitwise %d AND %d Output = %d",a,b, a&b);// out put 8
        //Bitwise OR
    /*
        12 = 00001100 (In Binary)
        25 = 00011001 (In Binary)

        Bitwise OR Operation of 12 and 25
        00001100
        | 00011001
        ________
        00011101  = 29 (In decimal)
    */
    printf("\n Bitwise %d OR %d Output = %d",a,b, a|b);//ouput 29
        //Bitwise XOR
    /*
        12 = 00001100 (In Binary)
        25 = 00011001 (In Binary)

        Bitwise XOR Operation of 12 and 25
        00001100
        ^ 00011001
        ________
        00010101  = 21 (In decimal)
    */
    printf("\nBitwise %d XOR  %d Output = %d",a,b,a^b);//output 21
        //Bitwise complement
    /*
        12 =  00001100 (In Binary)

        Bitwise complement Operation of 35
        ~ 00001100
        ________
         11110011=  243 (In decimal) ->Decimal from signed 2's complement -13
    */
    printf("\nBitwise complement %d Output = %d",a, ~a);// Are you think out put is 243 or -13?
        // Shift Operators
    /*
        12 =  00001100 (In Binary)
        Right shift
        12>>1 = 0000110 = 6
        Left shift
        12<<1 = 000011000 = 24
    */

    printf("\nShift Rigth %d Output = %d",a, a>>1);
    printf("\nShift Left  %d Output = %d",a, a<<1);
    //Toán tử logic (Logical Operators).
    // 1 đúng 0 sai
        //AND
    printf("\n%d >= 0 AND %d>=0 : %s ",a,b, a>=0&&b>=0);
        //OR
    printf("\n%d >= 0 AND %d>=0 : %s ",a,b, a>=0||b<0);
        //NOT
    printf("\n%d >= 0 AND %d>=0 : %s ",a,b, a!=0||b!=0);
    
    // Các toán tử khác sẽ được ôn và giới thiệu tiếp
}   