---
layout: post
title:  "selectionsort"
subtitle: "using vector"
date:   2019-01-03 12:36:01
categories: [algorithm]
---

## 선택정렬



##### vector를 이용하여 구현한 선택정렬이다.



~~~

void selectionsort(vector<int>&v) {
	int tmp = 0;
	for (int i = 0; i < v.size()-1; i++) //마지막 원소는 하지않아도된다.
	{
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[min] > v[j])
				min = j;
		}
		//swap
		tmp = v[i];
		v[i] = v[min];
		v[min] = tmp;
	}
}
int main()
{
	vector<int> arr= {21,10,12,20,25,13,15,22};
	selectionsort(arr);
	for(int i=0;i<arr.size();i++)
		cout << arr[i] << " ";
}
~~~

