#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
bool visited[20][20][80];
char maze[20][20];
int startx;
int starty;
int keycnt;
int M;
int N;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
int bitcount(int x)
{
	if (x == 0)
	{
		return 0;
	}
	return x % 2 + bitcount(x / 2);
}
int BFS()
{
	int cnt = 0;
	queue<pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {starty,startx},{0,0} });
	visited[starty][startx][0] = true;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int found = q.front().second.second;
		q.pop();
		if (bitcount(found) == keycnt)
		{
			return cnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int tmpy = y + dy[i];
			int tmpx = x + dx[i];
			if (tmpy < 0 || tmpy >= M || tmpx < 0 || tmpx >= N)
			{
				continue;
			}
			if (maze[tmpy][tmpx] - 0 >= 65 && maze[tmpy][tmpx] - 70 && !visited[tmpy][tmpx][found])
			{
				if (found & (1 << maze[tmpy][tmpx] - 65))
				{
					visited[tmpy][tmpx][found] = true;
					q.push({ {tmpy,tmpx},{cnt + 1,found} });
				}
			}
			if (maze[tmpy][tmpx] - 0 >= 97 && maze[tmpy][tmpx] - 0 <= 102 && !visited[tmpy][tmpx][found])
			{
				visited[tmpy][tmpx][found] = true;
				q.push({ {tmpy,tmpx},{cnt + 1,found | (1 << (maze[tmpy][tmpx] - 97))} });
			}
			if (maze[tmpy][tmpx] == '*' && !visited[tmpy][tmpx][found])
			{
				visited[tmpy][tmpx][found] = true;
				q.push({ {tmpy,tmpx},{cnt + 1,found} });
			}
		}
	}
	return -1;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		keycnt = 0;
		memset(maze, 0, sizeof(maze));
		memset(visited, false, sizeof(visited));
		cin >> M >> N;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == '@')
				{
					maze[i][j] = '*';
					starty = i;
					startx = j;
				}
				if (maze[i][j] - 0 >= 97 && maze[i][j] <= 102)
				{
					keycnt++;
				}
			}
		}
		cout << BFS() << '\n';
		testcase--;
	}
	return 0;
}