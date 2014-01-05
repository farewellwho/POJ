#include <algorithm>
#include <iostream>
#include <string.h>
char phones[100000][9];
int n;
int Mapping[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

using namespace std;

int StrCmp(const void* str1, const void* str2);

void Convert2StandForm(char* memorable, char* dest);

void StatAndOutput();

int main()
{
	int i = 0;
	char temp[500];
	cin >> n;
	while (i < n)
	{
		cin >> temp;
		Convert2StandForm(temp, phones[i++]);
	}
	qsort(phones, n, 9, StrCmp);
	StatAndOutput();
	return 0;
}

void StatAndOutput()
{
	int cnt = 1;
	bool hasDuplicates = false;
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (strcmp(phones[i], phones[i + 1]) == 0)
		{
			cnt++;
			hasDuplicates = true;
			continue;
		}
		if (cnt > 1)
		{
			cout << phones[i] << " " << cnt << endl;
			cnt = 1;
		}
	}
	if (cnt > 1)
	{
		cout << phones[i] << " " << cnt << endl;
		cnt = 1;
	}
	if (!hasDuplicates)
	{
		cout << "No duplicates." << endl;
	}
}

void Convert2StandForm(char* memorable, char* dest)
{
	int n = strlen(memorable);
	int k = 0;
	for (int i = 0; i <	n; i++)
	{
		if (k == 3)
		{
			dest[k++] = '-';
		}
		if (memorable[i] >= 'A' && memorable[i] <= 'Z')
		{
			dest[k++] = Mapping[memorable[i] - 'A'] + '0';
		}
		if (memorable[i] >= '0' && memorable[i] <= '9')
		{
			dest[k++] = memorable[i];
		}
	}
}

int StrCmp(const void* str1, const void* str2)
{
	return strcmp((char*)str1, (char*)str2);
}