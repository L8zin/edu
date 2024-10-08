/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void){
	int s = 0;
	int e = 0;
	// Fråga om start och slut
	printf("Start value: ");
	scanf("%d",&s);
	printf("End value: ");
	scanf("%d",&e);

	// Börja på startvärde och gå till och *med* slutvärde
	for(int i = s; i <= e; i++){

		// satserna man vill utföra flera gånger skrivs här
		printf("%d\n",i);

	}
	printf("Normal exit.\n");
	return 0;
}