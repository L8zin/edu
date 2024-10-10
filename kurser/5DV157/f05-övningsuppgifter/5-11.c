/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

int read_number(char s[]) {
	int n;
	printf("%s: ",s);
	scanf("%d",&n);
	return n;
}

double f_read_number(char s[]) {
	double n;
	printf("%s: ",s);
	scanf("%lf",&n);
	return n;
}

double F2C(double F) {
	return (F-32.0)/1.8;
}

double C2F(double C) {
	return C*1.8+32.0;
}

void menu() {
	printf("1. Convert from F to C\n");
	printf("2. Convert from C to F\n");
}

void sel(int i,int lo, int hi) {
	if (i < lo || i > hi) {
		printf("Selection out of range (%d-%d)\n",lo,hi);
	}
}

int main(void) {
	int i;
	double T;
	do {
		menu();
		i = read_number("Enter your selection:");
		sel(i,1,2);
	} while(i < 1 || i > 2);

	if (i == 1) {
		T = f_read_number("Enter the temperature in degrees Fahrenheit: ");
	} else {
		T = f_read_number("Enter the temperature in degrees Celsius: ");
	}
	// Känns som skumma funktioner i intstruktionerna så gör lite eget här
	if (i == 1) {
		printf("%.2lf F is %.2lf C\n",T,F2C(T));
	} else {
		printf("%.2lf C is %.2lf F\n",T,C2F(T));
	}


	

}