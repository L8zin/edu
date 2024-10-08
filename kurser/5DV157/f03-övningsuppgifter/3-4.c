/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void){
	int n = 0;
	// Fråga användaren hur många varv som de vill att programmet ska göras
	printf("How many loops?: ");
	scanf("%d",&n);

	for(int i = 0; i < n; i++){

		// satserna man vill utföra flera gånger skrivs här
		printf("%d\n",i);

	}
	printf("Normal exit.\n");
	return 0;
}