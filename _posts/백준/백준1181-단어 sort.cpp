#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main() {

	vector<pair<int,string>> l;
	int x;
	cin >> x;
	l.resize(x);
	for(int i=0; i<x;i++)
	{
		cin >> l[i].second;
		l[i].first = (l[i].second).length();
	}
	sort(l.begin(), l.end());

	cout << l[0].second << endl;
	for (int i = 1; i < x; i++)
	{
		if(l[i-1].second != l[i].second)
			cout << l[i].second << endl;
	}
	return 0;
}
