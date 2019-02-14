// sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include<iostream>
#include<vector>
using namespace std;

struct edge {
	int start;
	int dest;
};

vector<edge> q;

int bfs() {
	int cnt = 1;
	vector<int> virus;
	virus.push_back(1);
	while (!virus.empty())
	{
		int a = virus.front();
		virus.pop_back();
		

		int i = 0;
		while (i < q.size())
		{
			if (q[i].start == a)
			{
				virus.push_back(q[i].dest);
				cnt++;
				q.erase(q.begin() + i);
			}
			else i++;
		}
	}
	return cnt;
}

int main() {
	int comn, edgen;
	int s, d;
	edge x;
	cin >> comn;
	cin >> edgen;


	for (int i = 0; i < edgen; i++)
	{
		cin >> x.start >> x.dest;
		q.push_back(x);
	}

	cout << bfs() << endl;
	return 0;
}
