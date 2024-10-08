/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int main(void) {
	int n = 0;
	double f = 0;
	double sum = 0;
	

	printf("How many numbers to sum? ");
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++) {

		printf("Enter a floating point number: ");
		scanf("%lf",&f);
		sum += f;

	}
	printf("the sum is: %lf\n",sum);
}