#include<iostream>
using namespace std;
bool visited[10001];
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
		int cnt = 1;
		int disknum;
		cin >> disknum;
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