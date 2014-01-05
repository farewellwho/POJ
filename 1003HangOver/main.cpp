#include <iostream>

using namespace std;

int main()
{
	float c;
	int i = 2;
	float sum = 0;
	while ((cin >> c) && c != 0.00f)
	{
		sum = 0;
		i = 2;
		while (sum < c)
		{
			sum += 1.0f / i++;
		}
		cout << (i - 2) << " card(s)" << endl;
	}
	return 0;
}