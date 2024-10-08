/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void) {

	int i = 0;
	int n = 0;
	
	// Fråga användaren hur många varv som de vill att programmet ska göras
	printf("How many loops?: ");
	scanf("%d",&n);

	
	
	while (i< n) {

		printf("%d\n",i);
		// Viktigt att inkrementera 'i' varje loop
		i++;

	}
	return 0;
}