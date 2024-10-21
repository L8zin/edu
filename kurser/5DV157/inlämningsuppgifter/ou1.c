/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
CS-användarnamn: tfy24len
epost: luej0002@student.umu.se

Inlämningsuppgift 1, Shopping assistant:
Ett program som räknar ihop priser i utländsk valuta
och konverterar till SEK.
*/

// Inkludera header filen för standard input output.
#include <stdio.h>

// Börja main-funktionen.
int main(void){

	// Växlingskurs. Ska vara 1 vid programstart.
	double rate = 1; 

	// För val i menyn.
	int choice = 0; 

	// Senaste inmatade priset.
	double latestInput; 

	// Summan av alla inmatade priser.
	double sum; 

	printf("Your shopping assistant\n");
	
	// Hela programmet körs i en do-while loop så att den kan upprepas.
	do {

		// Skriv ut meny.
		printf("\n1. Set exchange rate in SEK (current rate: %.2f)\n",rate);
		printf("2. Read prices in the foreign currency\n");
		printf("3. End\n");
		printf("\n Enter your choice (1 - 3): ");

		// Vänta på menyval (choice) av användaren.
		scanf("%d",&choice);
		printf("\n");

		switch (choice){

			// Menyval 1: Ändra växlingskurs
			case 1: 

				printf("Enter exchange rate: ");
				scanf("%lf",&rate);
				break;

			// Menyval 2: Addera priser och mata ut i SEK.
			case 2: 

				// Återställ variabler.
				latestInput = 0; 
				sum = 0;

				// Lägger ihop alla priser som matas in.
				do {
					sum += latestInput;
					printf("Enter price (finish with < 0): ");
					scanf("%lf",&latestInput);

				} while (latestInput >= 0);

				//Skriver ut 'sum' och produkten av exchange rate och 'sum'.
				printf("\nSum in foreign currency: %.2lf\n",sum);
				printf("Sum in SEK: %.2lf\n",rate * sum);
				break;
			
			// Menyval 3: Tomt eftersom programmet bara ska avslutas.
			case 3: 

				break;

			// Kommer att köras om menyvalet är ogiltigt. 
			default: 

				printf("Not a valid choice!\n");
			
		}

	// While loopen körs så länge inte menyval 3 väljs, dvs då i = 3.
	} while(choice != 3);

	// Avsluta programmet. '\n\n' ger en blankrad efter.
	printf("End of program!\n\n");
	return 0;
}