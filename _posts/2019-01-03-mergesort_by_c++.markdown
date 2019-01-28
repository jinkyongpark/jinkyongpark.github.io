
---
layout: post
title:  "Merge sort"
subtitle: "using vector"
date:   2019-01-03 12:36:01
categories: [algorithm]
---
<h3>vector를 사용해 구현한 mergesort입니다.</h3>
~~~
// sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int left, int right, int mid) {
	vector<int> ret;
	int l = left, mnext = mid + 1, copy=0;

	while (l <= mid && mnext <= right) {
		if (v[l] < v[mnext])
			ret.push_back(v[l++]);
		else if(v[l] > v[mnext])
			ret.push_back(v[mnext++]);
	}
	while (l <= mid)
		ret.push_back(v[l++]);
	while (mnext <= right)
		ret.push_back(v[mnext++]);

	for (int k = left; k <= right; k++)
		v[k] = ret[copy++];

	for (int i = 0; i < v.size(); i++)
		cout << v[i]<<" ";
	cout << endl;
}

void mergesort(vector<int>& v, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort(v, start, mid);
		mergesort(v, mid + 1, end);

		merge(v, start, end, mid);
	}
}
int main()
{
	vector<int> arr= {21,10,12,20,25,13,15,22};
	mergesort(arr, 0, arr.size() - 1);
	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";
}
~~~
