---
layout: post
title:  "플로이드-워셜 알고리즘 "
subtitle: "using vector"
date:   2019-02-18 2:23:01
categories: [algorithm]


---

## Floyd-Warshall algorithm

최단거리알고리즘중하나다.

모든 최단경로를 구하는 문제다.

거리를 저장하는 구조는 2차원 배열이된다.

obtimal substructure의 개념을 이용하여 최단 경로를 찾는다.

* obtimal substructure란

: 특정한 경로안에 무수히 많은 경로가 있을 때, 중간 정점들이 각각 최단이 된다면 이를 모두 이은 경로 또한 최단이 된다.



사용관계

[img](/assets/floyd.PNG)

D(i에서 j까지 정점 K를 경로에 포함할 수 있을 때 비용)

= min(

D(i에서 j까지 정점 K-1까지 포함할 수 있을 때 비용),

D(i에서 k까지 정점 K-1까지 포함할 수 있을 때 비용) +

D(k에서 j까지 정점 K-1까지 포함할 수 있을 때 비용)

)

psuedo-code

~~~
D[][] : 모든경로에 대한 비용을 저장
P[][] : 직전의정점을저장한 테이블
~~~





//백준11404

~~~
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int main() {
	int n, m, dist[101][101];
	scanf("%d %d", &n, &m);

	//초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j ? 0 : INF;
	//입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c);
	}
	//플로이드 와샬
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	//출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) //값이안들어간부분은 INF로 되어있으므로 다시 0으로 바꿔준다.
				dist[i][j] = 0;
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
~~~





참고 : http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220797649276&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView