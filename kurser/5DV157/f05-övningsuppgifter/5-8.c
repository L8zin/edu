/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>
#include <math.h>

int max(int n1, int n2) {
	if (n1 > n2) {
		return n1;
	}
	else if (n2 > n1) {
		return n2;
	}
	else {
		printf("\nThe numbers are the same size or an error has occured\n");
		return 0;
	}

}
int max3(int n1, int n2, int n3) {
if (n1 > n2) {
		if (n1 > n3) {
			return n1;
		}
		else if (n3 > n1) {
			return n3;
		}
		else {
			printf("\nThe numbers are the same size or an error has occured\n");
			return 0;
		}

	}
	else if (n2 > n1) {
		if (n2 > n3) {
			return n2;
		}
		else if (n3 > n2) {
			return n3;
		}
		else {
			printf("\nThe numbers are the same size or an error has occured\n");
			return 0;
		}
	}
	else {
		printf("\nThe numbers are the same size or an error has occured\n");
		return 0;
	}

}

int main(void) {
	int n1 = 2;
	int n2 = 3;
	int n3 = 3;
	printf("%d\n",max(n1,n2));
	printf("%d\n",max3(n1,n2,n3));
}