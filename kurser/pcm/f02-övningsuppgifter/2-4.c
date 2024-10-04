/*Program som berättar om packningen är för tung*/
#include <stdio.h>

int main(void)
{
	float weight, limit; // Variabler för vikten är packningen och den maximala tillåtna vikten av packningen

	// fråga användare efter maxvikten, limit
	printf("Vad är maxvikten?:");
	scanf("%f",&limit);

	// fråga användare efter packningens vikt, weight
	printf("Hur mycket väger packningen?: ");
	scanf("%f",&weight);

	//
	if (weight > limit)
	{
		printf("Packningen är över viktgränsen!!!\n");
	} else if (weight < limit && weight >= 0)
	{
		printf("Yay! Packningen är under viktgränsen!\n");
	} else {
		printf("Vafan har du skrivt?\n");
	}
	
	printf("Normal exit\n");
	return 0;
}