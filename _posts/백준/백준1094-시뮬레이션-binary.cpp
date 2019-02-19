
#include <iostream>
using namespace std;


int main() {
	int n,b[7];
	cin >> n;
	int ans = 0;
	while (n > 0)
	{
		int r = n % 2;
		if (r) ans++;
		n = n / 2;

	}
	cout << ans;
	return 0;
}
