#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int>> vp;
int main(void)
{
	int T;//test case
	int N, L, k;// 개미수, 막대길이, k번째
	deque<int> idList;
	vector<int> fallList;
	vp ant;

	cin >> T;
	int pos, id;
	while (T--)
	{
		cin >> N >> L >> k;
		while (N--)
		{
			cin >> pos >> id;
			idList.push_back(id); //id순서기억
			id < 0 ? ant.push_back({ pos,id }) : ant.push_back({ L - pos,id });// 0혹은 L과의 거리
		}

		sort(ant.begin(), ant.end()); //떨어지는 순서대로 기록

		for (int i = 0; i < ant.size(); i++)
		{
			int frontValue = idList.front(), backValue = idList.back();


			// 떨어지는 시간이 같은 ㄱ여우
			if (i != ant.size() - 1 && ant[i].first == ant[i + 1].first)
			{
				if (frontValue < backValue)
				{
					fallList.push_back(frontValue);
					fallList.push_back(backValue);
				}
				else
				{
					fallList.push_back(backValue);
					fallList.push_back(frontValue);
				}

				//2개를 처리했으므로 
				idList.pop_back();
				idList.pop_front();
				i++;
			}
			else if (ant[i].second < 0)
			{
				fallList.push_back(frontValue);
				idList.pop_front();
			}
			else
			{
				fallList.push_back(backValue);
				idList.pop_back();
			}
		}
		cout << fallList[k - 1] << endl;

		ant.clear();
		idList.clear();
		fallList.clear();
	}

	return 0;
}
