---
layout: post
title:  "Kruskal 알고리즘"
subtitle: "by C++"
date:   2019-02-16 12:36:01
categories: [algorithm]


---

## Kruskal 알고리즘





Cycle형성 체크방법

1. DFS그래프 탐색 기법
2. Disjoint set (Union-Find알고리즘)

2번이 성능 더 Good



~~~
#include <iostream>
#include<algorithm>
#include<vector>
#define max_size 9

using namespace std;
int root[max_size];
int rankk[max_size]; //트리 높이 저장



/***************union-find****************/
void make_set() {
	for (int i = 1; i < max_size; i++) {
		root[i] = i;
		rankk[i] = 0;
	}
	
}

int find(int x)
{
	if (root[x] == x)
		return x;
	else
		//return root[x]= find(root[x]); //find하면서 만난 모든 값으 부모 노드를 root로 바꿈
		return find(root[x]);
}

void unionn(int x, int y)
{
	x = find(x);
	y = find(y);
	root[y] = x;
}
int main()
{
	int v = 7;
	int e = 9;


	vector<pair<int, pair<int,int>>> g;
	
	g.push_back(make_pair(29, make_pair(1, 2)));
	g.push_back(make_pair(10, make_pair(1, 7)));
	g.push_back(make_pair(16, make_pair(2, 3)));
	g.push_back(make_pair(15, make_pair(2, 7)));
	g.push_back(make_pair(12, make_pair(3, 4)));
	g.push_back(make_pair(18, make_pair(4, 7)));
	g.push_back(make_pair(22, make_pair(4, 5)));
	g.push_back(make_pair(25, make_pair(5, 7)));
	g.push_back(make_pair(27, make_pair(5, 6)));

	make_set();

	sort(g.begin(), g.end());
	
	int i = 0;
	vector<int> mst;
	
	while (mst.size()!=v-1)
	{
		int w = g[i].first;
		int x = g[i].second.first;
		int y = g[i].second.second;
		
		if (find(x) != find(y))
		{
			unionn(x, y);
			mst.push_back(w);
		}
		i++;
	}

	
	
	for (int i = 0; i < v-1; i++)
		cout << mst[i]<<" ";

	
	return 0;
}
~~~

