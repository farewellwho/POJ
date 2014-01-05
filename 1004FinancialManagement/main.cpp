#include <stdio.h>

int main()
{
	float closingBalance = 0;
	float avgBalance = 0;
	for (int i = 0; i < 12; i++)
	{
		scanf("%f", &closingBalance);
		avgBalance += closingBalance;
	}
	printf("$%.2f\n", (avgBalance / 12));
	return 0;
}