/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void){
	int sum = 0;
	//summera alla tal 0-10 i variablen sum
	for(int i = 0; i <= 10;i++){
		// satserna man vill utföra flera gånger skrivs här
		printf("i = %d\n",i);
		printf("%d\n",sum += i);
	}
	printf("Normal exit.\n");
	return 0;
}