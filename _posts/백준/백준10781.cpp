
#include<iostream>
#include <vector>
using namespace std;


int main()
{
	int n, x,data;
	vector<int> a;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		if(data<x)
			a.push_back(data);
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	return 0;
}