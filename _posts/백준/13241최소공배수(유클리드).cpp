
#include <iostream>
typedef long long int in;

using namespace std;
in gcd(in a, in b)
{
	while (b != 0)
	{
		in c = a % b;
		a = b;
		b = c;
	}
	return a;
}
in lcm(in a, in b)
{
	return (a*b) / gcd(a, b);
}

int main()
{
	in x, y;
	cin >> x >> y;
	cout << lcm(x, y);
}