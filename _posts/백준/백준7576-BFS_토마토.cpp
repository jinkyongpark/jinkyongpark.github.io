// sort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <queue>

#include <stdio.h>
using namespace std;

int m, n;
int **box;
int cnt=0; //cnt가 0이되면 종료



struct col {
	int x, y;
};
queue<col> que;


int bfs() {
	int x, y, xx, yy;
	int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

	int ans = 1;
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size ; ++i)
		{
			col c = que.front();
			que.pop();
			x = c.x, y = c.y;

			for (int j = 0; j < 4; j++)
			{
				xx = x + dir[j][0];
				yy = y + dir[j][1];

				if (xx >= n || xx < 0 || yy<0 || yy>=m)
					continue;
				else if (box[xx][yy] == 0)
				{
					que.push({ xx,yy });
					box[xx][yy] = 1;
					cnt--;
				}
				else if (box[xx][yy] == -1 )
					continue;
				
			}
			if (cnt == 0)
			{
				printf("%d\n", ans);
				return 0;
			}
			
		}
		ans++;
	}
	printf("-1");
	return 0;
}








int main() {
	

	scanf_s("%d %d", &m, &n);
	


	box = new int*[n];
	for (int i = 0; i < n; i++)
	{
		box[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &box[i][j]);
			if (box[i][j] == 1)
				que.push({ i,j });
			else if (box[i][j] == 0)
				cnt++;
		}
	}


	if (cnt == 0)
		printf("0");
	else if (cnt == m * n)
		printf("-1");
	else
		bfs();

	
	return 0;
}
