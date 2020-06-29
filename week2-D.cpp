#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		int itemnum;
		cin >> itemnum;
		vector<pair<int, int>> v;
		for (int i = 0; i < itemnum; i++)
		{
			string tmp;
			int starttime;
			int endtime;
			cin >> tmp >> starttime >> endtime;
			v.push_back({ endtime,starttime });
		}
		int cnt = 1;
		sort(v.begin(), v.end());
		int firstendtime = v[0].first;
		for (int i = 1; i < itemnum; i++)
		{
			if (firstendtime <= v[i].second)
			{
				firstendtime = v[i].first;
				cnt++;
			}
		}
		cout << cnt << '\n';
		testcase--;
	}
	return 0;
}