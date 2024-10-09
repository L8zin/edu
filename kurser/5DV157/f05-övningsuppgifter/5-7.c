/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int read_number(char s[]) {
	int n;
	printf("please enter number %s: ",s);
	scanf("%d",&n);
	return n;
}

int main(void)
{	
	int n1, n2;
	n1 = read_number("n1");
	n2 = read_number("n2");

	printf("The sum of n1 and n2 is : %d.\n", n1 + n2);
	printf("The difference between n1 and n2 is : %d.\n", n1 - n2);
	printf("The product of n1 and n2 is : %d.\n", n1 * n2);

	

}