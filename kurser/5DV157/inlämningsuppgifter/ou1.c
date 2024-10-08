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
	// Exchange rate: Eftersom exchange rate ska vara 1 i vid programstart så tilldelas den 1 här.
	double rate = 1; 
	// Index: Används för val i menyn.
	int i = 0; 
	// Senaste inmatade priset.
	double latestPrice = 0; 
	// Summan av alla inmatade priser.
	double sum = 0; 

	printf("Your shopping assistant\n");
	
	// Hela programmet körs i en do-while loop så att den kan upprepas.
	do {

		// Skriv ut meny.
		printf("\n1. Set exchange rate in SEK (current rate: %.2f)\n2. Read prices in the foreign currency\n3. End\n",rate);
		printf("\n Enter your choice (1 - 3): ");

		// Vänta på menyval (i) av användaren.
		scanf("%d",&i);

		switch (i){

			// Menyval 1: Frågar användare efter exchange rate och lagrar i variablen 'rate'.
			case 1: 

				printf("\nEnter exchange rate: ");
				scanf("%lf",&rate);
				break;

			// Menyval 2: Addera priser och mata ut i SEK.
			case 2: 

				// Tilldelas noll så att de återställs varje gång meynval 2 väljs.
				latestPrice = 0; 
				sum = 0;
				
				// Behövs för att ge en ny rad efter menyn men inte i varje loop.
				printf("\n");

				// Lägger ihop alla priser som användaren matar in i variabeln 'sum'.
				do {
					sum += latestPrice;

					printf("Enter price (finish with < 0): ");
					scanf("%lf",&latestPrice);

				} while (latestPrice >= 0);

				//Skriver ut 'sum' och produkten av exchange rate och 'sum'.
				printf("\nSum in foreign currency: %.2lf\n",sum);
				printf("Sum in SEK: %.2lf\n",rate * sum);
				break;
			
			// Menyval 3: Tomt eftersom programmet bara ska avslutas.
			case 3: 
				break;

			// Kommer att köras om menyvalet är ogiltigt. 
			default: 
				printf("\nNot a valid choice!\n");
			
		}

	// While loopen körs så länge inte menyval 3 väljs, dvs då i = 3.
	} while(i !=3);

	// Avslutar programmet. Notera dubbla newline-karaktärer. Detta ger en blankrad efter "End of program"
	printf("\nEnd of program!\n\n");
	return 0;
}