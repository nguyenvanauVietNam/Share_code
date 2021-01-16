#include <stdio.h>

/*
int	                    %d
char	                %c
float	                %f
double	                %lf
short int	            %hd
unsigned int	        %u
long int	            %li
long long int	        %lli
unsigned long int	    %lu
unsigned long long int	%llu
signed char	            %c
unsigned char	        %c
long double	            %Lf
- Nhập
  + Nhập ký tự
  + Nhập số nguyên
  + Nhập chuỗi
- Xuất
  + Xuất ký tự
  + Xuất số nguyên
  + Xuất chuỗi
*/
int main(void)
{
  //khai báo biến nhập ký tự
    char KY_TU;
  //Khai báo biến lưu trữ số nguyên
    int SO_NGUYEN;
  //Khai báo viên lưu trữ chuối trong c
    char CHUOI_100_KT[100];
    //Nhập
    printf ("\nNhap vao ky tu: ");
    scanf("%c",&KY_TU);
    printf ("\nNhap vao so nguyen: ");
    scanf("%d",&SO_NGUYEN);
    fflush(stdin);
    printf ("\nNhap vao chuoi: ");
    fgets(CHUOI_100_KT, sizeof(CHUOI_100_KT), stdin); 
    //fflush(stdin);
    //xuất
    printf ("\nKy tu nhap vao : %c",KY_TU);
    printf ("\nSo nguyen nhap vao : %d",SO_NGUYEN);
    printf ("\nChuoi nhap vao: %s", CHUOI_100_KT);
}