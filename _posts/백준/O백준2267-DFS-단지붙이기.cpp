#include <cstdio>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;
#define MAX_SIZE 26
int N, M;
char map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
int dx[4] = { 1, -1, 0, 0 };    //동 서 남 북
int dy[4] = { 0, 0, -1, 1 };    //동 서 남 북

vector<int> bfs() {
	vector<int> b;
	while (1) {
		int i, j;
		queue<pair<int, int>> q;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if ((visit[i][j] == 0) && map[i][j] == '1')
				{
					q.push(make_pair(i, j));
					visit[i][j] = 1;
					break;
				}
			}
			if (!q.empty())
				break;
		}
		if (i == N && j == N)
			break;

		int cnt = 1;
		while (!q.empty())
		{
			int x = q.front().second;
			int y = q.front().first;

			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int xx = x + dx[i], yy = y + dy[i];
				if (xx < 0 || xx >= N || yy < 0 || yy >= N)
					continue;
				if (visit[yy][xx] == 1)
					continue;
				if (map[yy][xx] != '1')
					continue;
				q.push(make_pair(yy, xx));
				visit[yy][xx] = 1;
				cnt++;
			}
		}
		b.push_back(cnt);
	}
	return b;
}
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf_s("%s", map[i]);
	
	vector<int> x = bfs();
	sort(x.begin(), x.end());
	int size = x.size();
	printf("%d\n", size);
	for (int i = 0; i < size; i++)
		printf("%d\n", x[i]);
	return 0;
}









참고
#include <cstdio>
#include <algorithm>

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, k, cnt[26 * 26];
char arr[26][26];

void dfs(int x, int y) {
    arr[x][y] = '0', cnt[k]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (arr[nx][ny] == '1') dfs(nx, ny);
    }
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%s", arr[i]+1);

    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
        if (arr[i][j] == '1') dfs(i, j), k++;

    std::sort(cnt, cnt + k);

    printf("%d\n", k);
    for (i = 0; i < k; i++) printf("%d\n", cnt[i]);

    return 0;
}