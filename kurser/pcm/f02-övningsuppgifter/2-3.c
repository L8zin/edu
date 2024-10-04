#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool i = true; // Kan antingen vara 0/1 eller false/true
	bool j = true; // Kan antingen vara 0/1 eller false/true

	if (i)
	{
		printf("i was true!\n");
	}
	if (j)
	{
		printf("j was true!\n");
	}
	if (i && j)
	{
		printf("i && j was true!\n");
	}
	if (i || j)
	{
		printf("i || j was true!\n");
	}

	printf("Normal Exit\n");
	return 0;
}