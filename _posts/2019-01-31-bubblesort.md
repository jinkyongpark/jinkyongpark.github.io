---
layout: post
title:  "버블정렬"
date:   2019-01-31 08:43:59
author: kyong
categories: algorithm
comments : true
---

## Bubblesort

c++로 구현한 버블정렬이다.



~~~

#include <algorithm>
#include <iostream>

using namespace std;

void swap(int &a, int&b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int n;
	int x[1000];
	int p = 0;
	cin >> n;
	for (int i =0 ; i < n; i++)
	{
		cin >> x[i];
	}

	for (int i = 0; i < n-1; i++)
	{
		p = 0;
		while (p < n-1)
		{
			if (x[p] > x[p + 1])
				swap(x[p], x[p + 1]);
			p++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
	return 0;
}

~~~





` 백준2750 `