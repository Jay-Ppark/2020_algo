#include<iostream>
#include<vector>
using namespace std;
int dy[4][2] = { {-1,1},{-1,1},{-1,1},{0,0} };
int dx[4][2] = { {-1,1},{1,-1},{0,0},{-1,1} };
int game[15][15];
bool visited[15][15];
int cnt;
void Initgame()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			game[i][j] = -1;
		}
	}
}
void Initvisited()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			visited[i][j] = false;
		}
	}
}
void solve(int y, int x, int direction, int color)
{
	if (direction == 1)
	{
		for (int i = 0; i < 2; i++)
		{
			int tmpy = y + dy[0][i];
			int tmpx = x + dx[0][i];
			if (tmpy >= 0 && tmpy < 15 && tmpx >= 0 && tmpx < 15)
			{
				if (color == game[tmpy][tmpx])
				{
					if (!visited[tmpy][tmpx])
					{
						cnt++;
						visited[tmpy][tmpx] = true;
						solve(tmpy, tmpx, 1, color);
					}
				}
			}
		}
	}
	else if (direction == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			int tmpy = y + dy[1][i];
			int tmpx = x + dx[1][i];
			if (tmpy >= 0 && tmpy < 15 && tmpx >= 0 && tmpx < 15)
			{
				if (color == game[tmpy][tmpx])
				{
					if (!visited[tmpy][tmpx])
					{
						cnt++;
						visited[tmpy][tmpx] = true;
						solve(tmpy, tmpx, 2, color);
					}
				}
			}
		}
	}
	else if (direction == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			int tmpy = y + dy[2][i];
			int tmpx = x + dx[2][i];
			if (tmpy >= 0 && tmpy < 15 && tmpx >= 0 && tmpx < 15)
			{
				if (color == game[tmpy][tmpx])
				{
					if (!visited[tmpy][tmpx])
					{
						cnt++;
						visited[tmpy][tmpx] = true;
						solve(tmpy, tmpx, 3, color);
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			int tmpy = y + dy[3][i];
			int tmpx = x + dx[3][i];
			if (tmpy >= 0 && tmpy < 15 && tmpx >= 0 && tmpx < 15)
			{
				if (color == game[tmpy][tmpx])
				{
					if (!visited[tmpy][tmpx])
					{
						cnt++;
						visited[tmpy][tmpx] = true;
						solve(tmpy, tmpx, 4, color);
					}
				}
			}
		}
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
		bool isgamefinished = false;
		Initgame();
		for (int i = 0; i < 225; i++)
		{
			int tmpy;
			int tmpx;
			cin >> tmpy >> tmpx;
			if (!isgamefinished)
			{
				if (i % 2 == 0)
				{
					game[tmpy - 1][tmpx - 1] = 0;
				}
				else
				{
					game[tmpy - 1][tmpx - 1] = 1;
				}
				for (int j = 1; j <= 4; j++)
				{
					cnt = 0;
					Initvisited();
					solve(tmpy - 1, tmpx - 1, j, i % 2);
					if (cnt == 5)
					{
						if (i % 2 == 0)
						{
							cout << i + 1 << " " << "B" << '\n';
						}
						else
						{
							cout << i + 1 << " " << "W" << '\n';
						}
						isgamefinished = true;
						break;
					}
				}
			}
		}
		testcase--;
	}
	return 0;
}