/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void){
	//skriver även om i = i+1 till i++
	for(int i = 4; i >= 0;i--){
		// satserna man vill utföra flera gånger skrivs här
		printf("%d\n",i);
	}
	printf("Normal exit.\n");
	return 0;
}