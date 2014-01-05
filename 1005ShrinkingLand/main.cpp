#include <stdio.h>

#define PI 3.14159

int main()
{
	int n, i = 0;
	float x, y;
	scanf("%d", &n);
	while (i++ < n)
	{
		scanf("%f %f", &x, &y);
		printf("Property %d: This property will begin eroding in year %d.\n", i, (int)(PI * (x * x + y * y) / 100) + 1 );
	}
	printf("END OF OUTPUT.");
	return 0;
}