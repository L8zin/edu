/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */
#include <stdio.h>

double mean3(int n1, int n2, int n3) {
	return (n1+n2+n3)/3.0;
}

int main(void) {

	int n1 = 12;
	int n2 = 3;
	int n3 = 4;

	printf("%.2lf\n",mean3(n1,n2,n3));

	printf("Normal exit.\n");
	return 0;
}