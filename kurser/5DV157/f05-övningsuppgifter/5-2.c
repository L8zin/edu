/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

double f_add(double a,double b) {
	double sum;
	sum = a + b;
	return sum;
}

int main(void) {
	double a = 123.0;
	double b = 456.7;
	printf("%lf\n",f_add(a,b));

	printf("Normal exit.\n");
	return 0;
	
}