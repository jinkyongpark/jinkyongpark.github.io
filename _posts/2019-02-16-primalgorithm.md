---
layout: post
title:  "Prim 알고리즘"
subtitle: "by C++"
date:   2019-02-16 12:36:01
categories: [algorithm]



---

## Prim 알고리즘





~~~
#include <cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include <functional>
#define max_size 9

using namespace std;


vector<vector<pair<int, int>>> edge;//도착지, weight
priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
bool visited[10001];
int v, e, c, k;
void prim(int v)
{
	visited[v] = true;
	printf("visit : %d\n", v);

	for (auto u : edge[v])
	{
		if (!visited[u.second])
			pq.push({ u.first,u.second });
	}//v와 연결된 간선의 정보(weight,도착정점)를 큐에 담음 
	//weight를 먼저담아야 weight를 기준으로 정렬가능

	while (!pq.empty())
	{
		auto w = pq.top();

		pq.pop();
		if (!visited[w.second]) {
			k += (w.first);
			prim(w.second);
			return;
		}
	}
}
int main()
{
	
	scanf_s("%d %d", &v, &e);
	edge.resize(v + 1);
	int x, y, z;
	for (int i = 0; i < e; i++)
	{
		scanf_s("%d %d %d", &x, &z, &y);
		edge[x].push_back({ z,y });
		edge[y].push_back({ z,x });
	}
	prim(1);// 1번 정점으로 트리 시작;
	printf("최소간선 : %d\n", k);
	/*
	입력예시
	7 9
	1 29 2
	1 10 6
	2 16 3
	2 15 7
	3 12 4
	4 18 7
	4 22 5
	5 27 6
	5 25 7
	*/

	return 0;
}
~~~

