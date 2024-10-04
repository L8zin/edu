#include <stdio.h>

int main(void)
{
	int n1, n2;

	printf("Enter the first number: ");
	scanf("%d",&n1);

	printf("Enter the second number: ");
	scanf("%d",&n2);

	printf("The sum of n1 and n2 is : %d.\n", n1 + n2);
	printf("The difference between n1 and n2 is : %d.\n", n1 - n2);
	printf("The product of n1 and n2 is : %d.\n", n1 * n2);
	printf("The integer quotient between n1 and n2 is : %d.\n", n1 / n2);
	printf("The integer remainder between n1 and n2 is: %d.\n", n1 % n2);

	printf("Normal exit\n");
	return 0;
}