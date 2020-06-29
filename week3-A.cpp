#include<iostream>
using namespace std;
int visited[10001];
void Init()
{
	for (int i = 0; i <= 10000; i++)
	{
		visited[i] = false;
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
		int disknum;
		cin >> disknum;
		int cnt = 1;
		for (int i = 0; i < disknum; i++)
		{
			int tmp;
			cin >> tmp;
			visited[tmp] = true;
			if (tmp != disknum)
			{
				if (!visited[tmp + 1])
				{
					cnt++;
				}
			}
		}
		Init();
		cout << cnt << '\n';
		testcase--;
	}
	return 0;
}