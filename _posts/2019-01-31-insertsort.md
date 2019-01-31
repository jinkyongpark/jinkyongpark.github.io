---
layout: post
title:  "삽입정렬"
date:   2019-01-31 08:43:59
author: kyong
categories: algorithm
comments : true
---



## Insertion sort



c++로 구현한 삽입정렬이다.





~~~

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n;
	int x[1000];
	int p ; //pointer
	int tmp;
	cin >> n;
	for (int i =0 ; i < n; i++)
	{
		cin >> x[i];
	}
	
	for (int i = 1; i < n ; i++)
	{
		int j;
		p = x[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (x[j] > p)
				x[j + 1] = x[j];
			else
				break;
		}
		x[j + 1] = p;
	}


	for (int i = 0; i < n; i++)
		cout << x[i] << endl;
	return 0;
}

~~~





` 백준 2750 `