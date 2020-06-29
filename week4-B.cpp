#include<iostream>
#include<queue>
using namespace std;
bool visited[500][500];
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int finy;
int finx;
void Init()
{
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			visited[i][j] = false;
		}
	}
}
int BFS(int y, int x, int mapsize)
{
	int cnt = 0;
	queue <pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int tmpy = q.front().first;
			int tmpx = q.front().second;
			q.pop();
			if (tmpy == finy && tmpx == finx)
			{
				return cnt;
			}
			for (int j = 0; j < 8; j++)
			{
				int ttmpy = tmpy + dy[j];
				int ttmpx = tmpx + dx[j];
				if (ttmpy >= 0 && ttmpx >= 0 && ttmpy < mapsize && ttmpx < mapsize)
				{
					if (!visited[ttmpy][ttmpx])
					{
						visited[ttmpy][ttmpx] = true;
						q.push({ ttmpy,ttmpx });
					}
				}
			}
		}
		cnt++;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		int mapsize;
		cin >> mapsize;
		int startx;
		int starty;
		cin >> startx >> starty;
		cin >> finx >> finy;
		cout << BFS(starty, startx, mapsize) << '\n';
		Init();
		testcase--;
	}
	return 0;
}