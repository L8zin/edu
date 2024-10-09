/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

double f_read_number(char s[]) {
	double n;
	printf("please enter number %s: ",s);
	scanf("%lf",&n);
	return n;
}

int main(void)
{	
	double n1, n2;
	n1 = f_read_number("n1");
	n2 = f_read_number("n2");

	printf("The sum of n1 and n2 is : %20.2f.\n", n1 + n2);
	printf("The difference between n1 and n2 is : %20.2f.\n", n1 - n2);
	printf("The product of n1 and n2 is : %20.2f.\n", n1 * n2);

	

}