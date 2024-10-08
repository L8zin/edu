/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int add(int a, int b) {
	int sum;
	sum = a +b;
	return sum;
	
}

int main(void) {
	int n1 = 123;
	int n2 = 456;
	int result;
	result = add(n1,n2);
	printf("The sum is %d\n",result);
	
	printf("Normal exit.\n");
	return 0;
}