---
layout: post
title:  "다익스트라 알고리즘 "
subtitle: "using vector"
date:   2018-11-08 2:23:01
categories: [algorithm]
---
<h3>다익스트라알고리즘</h3>


~~~


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

	cin >> V >> E>>K;

	

	d.assign(V, vector<int>(V, INF));

	

 

	// 점 점 weight 입력받기

	while (E--)

	{

		//a점과 b점사이의 c라는 weight

		int a,b,c;

		cin >> a >> b >> c;

		

		d[a - 1][b - 1] = c;

	}

	

	vector<int> r =	dijkstra();

 

	for (int i = 0; i<d.size(); i++)

	{

		if (r[i] == INF)

			cout << "INF" << endl;

		else

			cout << r[i] << endl;

	}

	return 0;

}
 ~~~

<a href="https://wkdtjsgur100.github.io/python-dijkstra/"title=>click</a>
