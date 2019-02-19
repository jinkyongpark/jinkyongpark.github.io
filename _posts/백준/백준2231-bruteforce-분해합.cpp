#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	bool x = false;
	cin >> n;
	int i;
	if (n != 1) {
		for (i = 1; i <= n; i++)
		{
			int tmp = i;
			int s = i;
			while (i > 0)
			{
				s += i % 10;
				i = i / 10;
			}
			i = tmp;
			if (s == n) {
				x = true;
				break;
			}

		}
	}

	if (x)
		cout << i << endl;
	else
		cout << 0 << endl;
	return 0;
}