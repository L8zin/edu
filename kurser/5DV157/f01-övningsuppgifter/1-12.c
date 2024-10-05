#include <stdio.h>

int main(void)
{
	float km_today; // Nuvarande mätarställning i kilometer
	float km_prev; // Föregående mätarställning i kilometer
	float l_km; // Förbrukning i l/km

	

	printf("Nuvarande mätarställning: ");
	scanf("%f",&km_today);

	printf("Föregående mätarställning: ");
	scanf("%f",&km_prev);

	printf("förbrukning under tiden (l/km): ");
	scanf("%f",&l_km);

	printf("Du har kört ungeför %.1f km\n", km_today - km_prev);
	printf("Under tiden har du förbrukat %.2f liter\n", (km_today-km_prev)*l_km);

	printf("Normal exit.\n");
	return 0;
}

