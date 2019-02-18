---
layout: post
title:  "다익스트라 알고리즘 "
subtitle: "using vector"
date:   2018-11-08 2:23:01
categories: [algorithm]

---

## Dijkstra algorithm

최단거리알고리즘중하나다.

하나의 정점에서 다른 모든 정점까지의 최단거리를 구한다.

<br><br>

입력예시

~~~
5 8 5
1 4 3
1 3 6
2 1 3
3 4 2
4 2 1
4 3 1
5 2 4
5 4 2
~~~

<br><br>

psuedo-code

~~~
d[a][b]: a에서 b사이의 거리 , V x V행렬 
visit[] : 방문여부 ,V, all False
w[] : 시작점에서 거리표시,V, all INF

w[start]= 0; //자기자신의 거리

loop(1):
	minVal = INF : 가장가까운노드의 거리
	nearV : 가장가까운 노드
	
	loop(x : 0~V):            
		if(방문하지 않음 and minVal보다 작은 거리):
			minVal = w[x]
			nearV = x
		
	if(minVal과  INF값이 같음): stop
	
	visit[nearV] = true
	
	loop(x : 0~V):
		if(방문한 노드): continue
		
	   //(start~x) comp (start~nearV)+(nearV~x)
		if (w[x] > w[nearV] + d[nearV][x]):
        	w[x] = w[nearV] + d[nearV][x]
		
~~~



1. 가장가까운거리를 가진  노드(nearV) 찾기 (loop)

2. 노드 방문

3. 원래거리와 nearV를지나쳐가는 거리 비교하여 update(loop)

   <br>

   <br>

    

```
#include"pch.h"
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

//V =점의 갯수 E = 간선갯수 K = 시작 점 번호
int V, E, K;

//graph의 인접리스트
vector<vector<int>> d;

vector<int> dijkstra()
{
	vector<int> s, w; //방문 여부, 최단 경로

	s.assign(V, false);
	w.assign(V, INF);

	w[K - 1] = 0;  //자신까지의 거리

	while (1)
	{
		int m = INF, N = -1;

		//가장 가까운 노드찾기
		for (int j = 0; j < V; j++)
		{
			//방문하지않았고 m보다 거리가 작으면 거리 update;
			if (!s[j] && (m > w[j]))
			{
				m = w[j]; 
				N = j;
			}
		}

		//최솟값이 무한대면 끝
		if (m == INF)
			break;

		//가장 가까운 노드방문
		s[N] = true;

		//d를 탐색하며 N(가장가까운)을 통해서 가는게 더가까운지 확인
		for (int j = 0; j < V; j++)
		{
			if (s[j]) continue;

			//N에서 j라는 점까지의 거리 + N까지의 거리
			int via = w[N] + d[N][j];
			if (w[j] > via)
				w[j] = via;
		}

	}

	return w;
}

int main()
{
	cin >> V >> E >> K;

	d.assign(V, vector<int>(V, INF));

	// 점 점 weight 입력받기
	while (E--)
	{
		//a점과 b점사이의 c라는 weight
		int a, b, c;
		cin >> a >> b >> c;
		d[a - 1][b - 1] = c;

	}

	vector<int> r = dijkstra();

	for (int i = 0; i < d.size(); i++)
	{
		if (r[i] == INF)
			cout << "INF" << endl;
		else
			cout << i <<":"<<r[i] << endl;
	}

	return 0;

}
```





참고 : 

[https://wkdtjsgur100.github.io/python-dijkstra/]: click	"click1"


