---
layout: post
title:  "Union-Find 알고리즘"
subtitle: "by C++"
date:   2019-02-16 12:36:01
categories: [algorithm]

---

## Union-Find 알고리즘

tree로 구현한 union-find알고리즘이다.

find()함수와 union()함수는 최적화 과정을 넣었다.



~~~
#include <iostream>
#define max_size 9

using namespace std;
int root[max_size];
int rankk[max_size]; //트리 높이 저장

void make_set() {
	for (int i = 1; i < max_size; i++) {
		root[i] = i;
		rankk[i] = 0;
	}
	
}

//최적화 find
int find(int x)
{
	if (root[x] == x)
		return x;
	else
		return root[x]= find(root[x]); //find하면서 만난 모든 값으 부모 노드를 root로 바꿈
		//return find(root[x]); //최적화 x
}

/* 최적화 x
void unionn(int x, int y)
{
x = find(x);
y = find(y);
root[y] = x;
}
*/

//최적화 union
void unionn(int x, int y)
{
	x = find(x);
	y = find(y);

	//root 같으면 합치지 x
	if (x == y)
		return;

	//높이가 낮은 트리를 높이가 높은 트리 밑에 넣는다. 
	if (rankk[x] < rankk[y])
		root[x] = y;
	else
		root[y] = x;
	
	if (rankk[x] == rankk[y]) //높이가같으면 합치고 x의높이 +1
		rankk[x]++;
}
int main()
{
	make_set();
	unionn(1, 2);
	unionn(4,5);
	unionn(6,1);
	unionn(3,7);
	unionn(7,8);
	unionn(2,5);

	for (int i = 1; i < max_size; i++)
		cout << root[i];

	return 0;
}
~~~





참고 : 

https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html