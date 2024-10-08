/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se

Inlämningsuppgift 2
 */

#include <stdio.h>
#include <stdbool.h>


bool equal(int a, int b) {
	if(a==b) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	int a = 0;
	int b = 0;
	printf("Enter 2 integers separated by a comma: ");
	scanf("%d,%d",&a,&b);
	printf("%s\n",equal(a,b)?"true":"false");
	printf("\nNormal exit.\n");
	return 0;
}