#include <stdio.h>
#include "ft_printf.h"

int main()
{
//	char *str1 = "Hello,";
//    char *str2 = " world";
//  //  int width = 50;
//	char c = 'F';
//    char r = 'R';
//	unsigned int num = 555;

	int i;
	int j;

//	int		a = 8;
//	int		b = 0;
//	char	c = 'a';
//	int		d = 2147483647;
//	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
//	int		i = 8;
//	int		j = -12;
//	int		k = 123456789;
//	int		l = 0;
//	int		m = -12345678;
//	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	char	*s = "-2147483648";
//	char	*t = "0x12345678";
//	char	*u = "-0";
//	 i = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','^?');
//	 printf("\n");
//	 j = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','^?');
//	 printf("\n");
//	 if (i == j)
//	     printf("i: %d, j : %d - all is ok\n", i, j);
//	 else
//	     printf("i: %d, j : %d - bad\n", i, j);

	i = ft_printf("%");
	j = printf("%");

//	i = ft_printf("%010.7s\n", "hello");
//	j = printf("%010.7s\n", "hello");

//	ft_printf("hello, %s.", NULL);
//	printf("hello, %s.", NULL);

//	i = ft_printf("FT: |%-06iu|\n", num); //%060i, %060.40i
//	j = printf("ST: |%-060i|\n", num);

//	i = ft_printf("%.0d\n", 0);
//	j = printf("%.0d\n", 0);

//	int INT_MIN;
//	INT_MIN = -2147483647;

//	i = printf("%0-8.5d\n", 34);
//	j = ft_printf("%0-8.5d\n", 34);

//	i = ft_printf("%-03p\n", &a);
//	j = printf("%-03p\n", &a);

    if (i == j)
        printf("i: %d, j : %d - all is ok\n", i, j);
    else
        printf("i: %d, j : %d - bad\n", i, j);
	return (0);
}