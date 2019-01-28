---
layout: post
title:  "Quicksort"
subtitle: "using vector, pivot= left"
date:   2018-11-11 03:08:01
categories: [algorithm]
---

퀵정렬은 divide and conquer방식입니다.

매우 빠른 수행속도를 가졌습니다.

시간복잡도 : O(log2n) 공간복잡도 : O(logn)


Divide(분할) : pivot값을 기준으로 2개의 부분집합으로 나눈다.

Conquer(정복) : 부분집합의 원소들 중 (pivot보다작은 값들) (pivot보다 큰 값)으로 정렬한다.

부분집합의 원소가 1개이하가 될 때까지 분할 정복이 반복됩니다.


~~~
#include <iostream>
#include <vector>
using namespace std;

void Quicksort(vector<int>& d, int left, int right)
{
	int pivot;
	int start, end, tmp;
	
	if (left < right) {   
		//이 조건은 Quicksort함수를 호출 했을 때,
		//다음과정을 실행할 지 결정한다.
		//left =right or left >right인 경우에는 실행하지 않게해준다.

		pivot = d[left];
		start = left;
		end = right;

		//start와 end가 교차될때 까지 반복
		while (start < end)
		{
			//pivot보다 큰거 나올때까지 start이동
			while (d[start] <= pivot && start <end)
				start++;
			//pivot보다 작은값나올때까지 end이동
			while (d[end] > pivot)
				end--;
			
			//1번 swap
			if (start < end)
			{
				tmp = d[end];
				d[end] = d[start];
				d[start] = tmp;
			}

		}
		
		//2번 swap
		d[left] = d[end];
		d[end] = pivot;

		//left(처음) ~ end-1  end+1 ~ right(끝)
		Quicksort(d, left, end - 1);
		Quicksort(d, end + 1, right);
	}
}
~~~

pivot을 제일 왼쪽 값으로 설정한 code입니다.


left와 right를 설정하고 

left는 pivot보다 작은 값이 나올때까지 이동 ,
right는 pivot보다 큰 value가 나올때까지 이동합니다.


*여기서 중요한 점은 d[start]<=pivot && start <end입니다.

start<end부분을 넣어주지 않으면
   ex : 5 4 3 2 1 에서 start가 범위를 넘어갈 수 있습니다.


*swap함수를 만들어 대체하면 더 좋은 코드가 될 수 있습니다.

~~~
int main(void)
{
	vector <int> lst;
	int N, data;  // N : 입력받을 개수
	cin >> N;

	while (N > 0)
	{
		N--;
		cin >> data;
		lst.push_back(data);
	}
	
	Quicksort(lst, 0, lst.size() - 1);
	
	return 0;
}
~~~

N(리스트의 개수)를 입력받고 리스트의 값들을 입력받습니다.


ex : 

(5) 4  3  2 (1)     ->2번 swap

 1 (4) 3 (2) 5      ->1번 swap

 1  2  3  4  5
