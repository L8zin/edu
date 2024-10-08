/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void){
	//I ska istället vara större än eller lika med 5.
	//skriver även om i = i+1 till i++
	for(int i = 0; i <= 5;i++){
		// satserna man vill utföra flera gånger skrivs här
		printf("%d\n",i);
	}
	printf("Normal exit.\n");
	return 0;
}