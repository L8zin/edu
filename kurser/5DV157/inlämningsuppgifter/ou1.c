/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se
 */

#include <stdio.h>
#include <stdbool.h>


int main(void){
	float rate = 1;
	int i;
	float latestPrice = 0;
	float sum = 0;
	printf("Your shopping assistant\n");

	do {
		printf("\n1. Set exchange rate in SEK (current rate: %.2f)\n2. Read prices in the foreign currency\n3. End\n",rate);
		printf("\n Enter your choice (1 - 3): ");
		scanf("%d",&i);

		switch (i){
			case 1: 
				printf("\nEnter exchange rate: ");
				scanf("%f",&rate);
				break;
			
			case 2:
				do {
					printf("Enter price (finish with < 0):");
					sum += latestPrice;
					scanf("%f",&latestPrice);
				} while (latestPrice >= 0);
				printf("\nSum in foreign currency: %f\n",sum);
				printf("Sum in SEK %f\n",rate * sum);


	
				break;
				
					
			case 3:
				printf("\nEnd of program!\n");
				break;

			default: 
				printf("\nNot a valid choice!\n");
			
		}


	} while(i !=3);
}