#include <stdio.h>

int main(void)
{
	int no_guests, no_sausages;
	printf("Hur många gäster?: ");
	scanf("%d",&no_guests);
	printf("Antal gäster: %d\n",no_guests);
	no_sausages = 2 * no_guests + 5;
	printf("Antal kovar som behövs: %d\n",no_sausages);
}
