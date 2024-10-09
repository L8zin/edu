/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>

double pyramidVol(double base, double height) {
	double vol = (base*height)/3.0;
	return vol;
}

int main(void) {
	double base = 10;
	double height = 6;
	printf("%.2lf\n",pyramidVol(base,height)) ;
}