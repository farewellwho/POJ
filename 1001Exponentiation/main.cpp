#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// Calculate multiple result of two number strings.The result is represented as a number string.
char* StringMultiply(char s1[], char s2[])
{
	int n1, n2, i, j, lOverflow, gOverflow, k, times, kk, reserve, flag;
	// n1, n2 length of number string
	n1 = strlen(s1); 
	n2 = strlen(s2);
	// position indicator
	i = n1 - 1;
	j = n2 - 1;
	// locale overflow
	lOverflow = 0;
	// global overflow
	gOverflow = 0;
	reserve = 0;
	// 
	flag = 0;
	// create the result string and reset each element to 0
	char* rs = new char[n1 + n2 + 1];
	*(rs + n1 + n2) = '\0';
	for (k = 0; k < n1 + n2; k++)
	{
		*(rs + k) = 0;
	}
	kk = n1 + n2 - 1;
	for (j = n2 - 1; j >= 0; j--)
	{
		if (s2[j] == '.')
		{
			reserve += (n2 - 1 - j);
			continue;
		}
		k = kk--;
		for (i = n1 - 1; i >= 0; i--)
		{
			if (s1[i] == '.')
			{
				if (flag == 0)
				{
					reserve += (n1 - 1 - i);
					flag = 1;
				}
				continue;
			}
			times = (s2[j] - '0') * (s1[i] - '0') + lOverflow;
			lOverflow = 0;
			if (times >= 10)
			{
				lOverflow = times / 10;
				times = times - lOverflow * 10;
			}
			// add times to result where the position is indicated by var k
			rs[k] = rs[k] + times + gOverflow;
			gOverflow = 0;
			if (rs[k] >= 10)
			{
				gOverflow = rs[k] / 10;
				rs[k] = rs[k] - gOverflow * 10;
			}
			k--;
		}
		if (lOverflow > 0 || gOverflow > 0)
		{
			rs[k] = rs[k] + lOverflow + gOverflow;
			lOverflow = 0;
			gOverflow = 0;
			if (rs[k] >= 10)
			{
				gOverflow = rs[k] / 10;
				rs[k] = rs[k] - gOverflow * 10;
			}
			k--;
		}
	}
	// convert numbers in rs to their string representation by adding '0', e.g., 0 to '0', 1 to '1' etc.
	for (k = 0; k < n1 + n2; k++)
	{
		rs[k] += '0';
	}
	// normalize the result string rs according to the criterion provided by the problem.
	char *normRs = new char[n1 + n2 + 1];
	flag = -1;
	int l = 0;
	int pointIdx = -1; // index in normRs where the symbol '.' should be placed.
	// trim prefix '0's
	for (k = 0; k < n1 + n2; k++)
	{
		if (reserve > 0 && k == n1 + n2 - reserve)
		{
			pointIdx = l;
			normRs[l++] = '.';
			normRs[l++] = rs[k];
			flag = 1;
			continue;
		}
		if (flag == -1 && rs[k] == '0')
		{
			continue;
		}
		flag = 1;
		normRs[l++] = rs[k];
	}
	normRs[l] = '\0';
	if (reserve > 0)
	{
		// trim sufix '0's
		flag = -1;
		k = l - 1;
		while (normRs[k] == '0' && k > pointIdx) { k--;};
		if (normRs[k] == '.')
		{
			k--;
		}
		normRs[k + 1] = '\0';
	}
	return normRs;
}

char* StringPower(char *s, int n)
{
	if (n == 1)
	{
		return StringMultiply(s, "1"); // can not return s itself directly. instead multiply it by "1" so as to format the output.
									   // think input 0.001 1 (you should output .001 instead of 0.001 in this case)
	}
	if (n % 2 == 0)
	{
		return StringPower(StringMultiply(s, s), n / 2);
	}
	else
	{
		return StringMultiply(s, StringPower(s, n - 1));
	}
}

int main()
{
	char s[7];
	int n;
	while (cin>>s>>n)
	{
		cout << StringPower(s, n) << endl;
	}
	return 0;
}