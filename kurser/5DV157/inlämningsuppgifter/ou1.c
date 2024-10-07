/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se

Inlämningsuppgift 1, Shopping assistant
 */

// Inkludera header filen för standard input output
#include <stdio.h>

// Börja main-funktionen
int main(void){

	float rate = 1; // Exchange rate: Eftersom exchange rate ska vara 1 i vid programstart så tilldelas den 1 här.
	int i; // Index: Används för val i menyn.

	printf("Your shopping assistant\n");

	do {
		printf("\n1. Set exchange rate in SEK (current rate: %.2f)\n2. Read prices in the foreign currency\n3. End\n",rate);
		
		printf("\n Enter your choice (1 - 3): ");
		scanf("%d",&i);

		switch (i){
			case 1: // Menyval 1: Frågar användare efter exchange rate och lagrar i variablen 'rate'.
				printf("\nEnter exchange rate: ");
				scanf("%f",&rate);
				break;

			case 2: // Menyval 2
				// Följande variabler deklareras här och tilldelas noll så att de återställs varje gång meynval 2 väljs.
				float latestPrice = 0; // Senaste inmatade priset.
				float sum = 0; // Summan av alla inmatade priser.

				// Lägger ihop alla priser som användaren matar in i variabeln 'sum'.
				do {
					printf("Enter price (finish with < 0):");
					sum += latestPrice;
					scanf("%f",&latestPrice);
				} while (latestPrice >= 0);

				//Skriver ut 'sum' och produkten av exchange rate och 'sum'.
				printf("\nSum in foreign currency: %f\n",sum);
				printf("Sum in SEK %f\n",rate * sum);
				break;
				
			case 3: // Menyval 3: Tomt eftersom programmet bara ska avslutas.
				break;

			default: // Kommer att köras om menyvalet är ogiltigt. 
				printf("\nNot a valid choice!\n");
			
		}

	// While loopen körs så länge inte menyval 3 väljs, dvs då i = 3.
	} while(i !=3);

	// Avsluta programmet. Notera dubbla newline-karaktärer. Detta ger en blankrad efter "End of program"
	printf("\nEnd of program!\n\n");
	return 0;
}