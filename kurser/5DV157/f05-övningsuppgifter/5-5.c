/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int read_number() {
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	return n;
}

int main(void) {
	int n;
	n =  read_number();
	printf("You entered the number %d\n",n);
	return 0;
}
