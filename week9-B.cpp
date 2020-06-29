#include<iostream>
#include<algorithm>
using namespace std;
int itemweight[501];
int itemvalue[501];
int dp[501][100001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		int itemnum;
		int maxweight;
		cin >> itemnum >> maxweight;
		for (int i = 1; i <= itemnum; i++)
		{
			cin >> itemweight[i];
		}
		for (int i = 1; i <= itemnum; i++)
		{
			cin >> itemvalue[i];
		}
		for (int i = 1; i <= itemnum; i++)
		{
			for (int j = 1; j <= maxweight; j++)
			{
				if (j - itemweight[i] >= 0)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - itemweight[i]] + itemvalue[i]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		cout << dp[itemnum][maxweight] << '\n';
		testcase--;
	}
	return 0;
}