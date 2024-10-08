/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void) {

	printf("\n1. ");
	for(int i = 1; i <= 20; i++) {
		printf("%d ",i);
	}

	printf("\n2. ");
	for(int i = 1; i <= 20; i += 2) {
		printf("%d ",i);
	}
	printf("\n3. ");
	for(int i = 30; i >= 0; i -=2) {
		printf("%d ",i);
	}
	printf("\n4. ");
	for(int i = 4; i <= 19; i++) {
		printf("%.1lf ",i*0.5);
	}
	printf("\nNormal exit.\n");
	return 0;
}
