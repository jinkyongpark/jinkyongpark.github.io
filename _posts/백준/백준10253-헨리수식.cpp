
#include<iostream>
#include <stdio.h>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int t;
	cin >> t;
	int a, b;

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		if (a != 1) {
			int j;

			do {
			
				j = b / a + 1;


				a = a * j - b;
				b = b * j;


				//기약분수만들기
				int gcdd = gcd(a, b);
				if (gcdd != 1)
				{
					a = a / gcdd;
					b = b / gcdd;
				}
			} while (a != 1);
			
		}

		cout << b << endl;
		
	}

	return 0;
}