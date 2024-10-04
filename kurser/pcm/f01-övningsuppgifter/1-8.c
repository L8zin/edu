#include <stdio.h>

int main(void)
{
	float n1, n2;
	printf("please enter n1: ");
	scanf("%f",&n1);

	printf("please enter n2: ");
	scanf("%f",&n2);

	printf("The sum of n1 and n2 is : %20.2f.\n", n1 + n2);
	printf("The difference between n1 and n2 is : %20.2f.\n", n1 - n2);
	printf("The product of n1 and n2 is : %20.2f.\n", n1 * n2);

	

}