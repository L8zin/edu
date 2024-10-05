#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int n1, n2;
	n1 = 3;
	n2 = 2;
	bool t;

	t = n1 == n2;
	if (t) { // Same as if (t == true)
	printf("n1 is equal to n2\n");
	}
	printf("Normal exit.\n");
	return 0;
}