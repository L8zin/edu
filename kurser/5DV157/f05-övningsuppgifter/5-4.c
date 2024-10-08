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

bool unequal(int a, int b) {
	return !equal(a,b);
}

int main(void) {
	int a = 0;
	int b = 0;
	printf("Enter 2 integers separated by a comma: ");
	scanf("%d,%d",&a,&b);
	printf("%s\n",unequal(a,b)?"true":"false");
	printf("\nNormal exit.\n");
	return 0;
}