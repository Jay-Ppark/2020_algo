#include<iostream>
using namespace std;
int team[10001];
bool visited[10001];
bool checked[10001];
int cnt;
void Init()
{
	for (int i = 0; i <= 10000; i++)
	{
		visited[i] = false;
		checked[i] = false;
	}
}
void DFS(int n)
{
	visited[n] = true;
	int nextstudent = team[n];
	if (!visited[nextstudent])
	{
		DFS(nextstudent);
	}
	else if (!checked[nextstudent])
	{
		cnt++;
		for (int i = nextstudent; i != n; i = team[i])
		{
			cnt++;
		}
	}
	checked[n] = true;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		int studennum;
		cin >> studennum;
		for (int i = 1; i <= studennum; i++)
		{
			cin >> team[i];
		}
		for (int i = 1; i <= studennum; i++)
		{
			if (!visited[i])
			{
				DFS(i);
			}
		}
		Init();
		cout << studennum - cnt << '\n';
		cnt = 0;
		testcase--;
	}
	return 0;
}