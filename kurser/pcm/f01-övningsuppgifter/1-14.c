#include <stdio.h>

int main(void)
{
	int s;
	printf("hur många sekunder?: ");
	scanf("%d",&s);

	printf("Antalet sekunder är: %d\n",s);
	printf("I minuter blir det %02d:%02d\n", s/60, s%60);
	printf("I timmar blir det %02d:%02d:%02d\n", s/3600, (s%3600)/60, s%60);

	printf("Normal exit.");
	return 0;
}