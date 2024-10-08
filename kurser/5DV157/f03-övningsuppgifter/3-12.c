/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void) {
	// create table header
	printf("i\ti*i\ti*i*i\n");
	printf("===\t====\t=====\n");

	// print table contents row by row
	for(int i = 1; i <= 30; i++) {
		printf("%d\t%d\t%d\n", i,i*i,i*i*i);
	}
	
	printf("Normal exit.\n");
	return 0;

}