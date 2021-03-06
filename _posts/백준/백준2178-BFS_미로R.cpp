// sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include<iostream>
#include<queue>
using namespace std;
#define MAX_SIZE 101
int N, M;
char map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
int dx[4] = { 1, -1, 0, 0 };    //동 서 남 북
int dy[4] = { 0, 0, -1, 1 };    //동 서 남 북

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));    //첫째pair 위치, 둘째pair 움직인거리
	visit[0][0] = 1;

	while (!q.empty()) {

		int x = q.front().first.second;
		int y = q.front().first.first;
		int z = q.front().second;
		cout << x << " " << y << " " << z << endl;
		q.pop();

		if (x == M - 1 && y == N - 1)
			return z;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visit[ny][nx] == 1)
				continue;
			if (map[ny][nx] != '1')
				continue;

			q.push(make_pair(make_pair(ny, nx), z + 1));
			visit[ny][nx] = 1;
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	cout << bfs();

	return 0;
}
