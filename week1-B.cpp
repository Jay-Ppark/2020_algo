#include<iostream>
#include<vector>
using namespace std;
int wholeday;
int rangeday;
int middle(vector<int>& cnt)
{
	if (rangeday & 2 != 0)
	{
		int midcnt = 0;
		for (int i = 0; i <= 200; i++)
		{
			midcnt = midcnt + cnt[i];
			if (midcnt > rangeday / 2)
			{
				return i * 2;
			}
		}
	}
	else
	{
		int fmedi = 0;
		int smedi = 0;
		int midcnt = 0;
		for (int i = 0; i <= 200; i++)
		{
			midcnt = midcnt + cnt[i];
			if (midcnt >= rangeday / 2 && fmedi == 0)
			{
				fmedi = i;
			}
			if (midcnt >= rangeday / 2 + 1 && smedi == 0)
			{
				smedi = i;
				return fmedi + smedi;
			}
		}
	}
}
int solve(vector<int>& v)
{
	vector<int> cnt(201, 0);
	for (int i = 0; i < rangeday; i++)
	{
		cnt[v[i]]++;
	}
	int result = 0;
	for (int i = rangeday; i < wholeday; i++)
	{
		if (middle(cnt) <= v[i])
		{
			result++;
		}
		cnt[v[i - rangeday]]--;
		cnt[v[i]]++;
	}
	return result;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		cin >> wholeday >> rangeday;
		vector<int> v;
		for (int i = 0; i < wholeday; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		cout << solve(v) << '\n';
		testcase--;
	}
	return 0;
}