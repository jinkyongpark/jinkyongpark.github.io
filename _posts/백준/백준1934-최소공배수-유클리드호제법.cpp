
#include<iostream>
#include <stdio.h>
using namespace std;


//유클리드 호제법
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
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main()
{
	int r;
	cin >>r;//갯수

	int a, b;
	for (int i = 0; i < r; i++)
	{
		cin >> a >> b;
		cout << lcm(a, b)<<endl;
	}
	return 0;
}