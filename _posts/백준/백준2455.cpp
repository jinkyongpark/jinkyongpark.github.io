
#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a, b, total=0;
	int max = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a >> b;
		total = total - a + b;
		if (total > max)
			max = total;
	}
	cout << max;
	return 0;
}