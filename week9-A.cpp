#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
	{
		return true;
	}
	else
	{
		return false;
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
		vector<pair<int, int>> v;
		int itemcnt;
		int maxweight;
		cin >> itemcnt >> maxweight;
		for (int i = 0; i < itemcnt; i++)
		{
			int tmp;
			cin >> tmp;
			v.push_back({ tmp,0 });
		}
		for (int i = 0; i < itemcnt; i++)
		{
			int tmp;
			cin >> tmp;
			v[i].second = tmp / v[i].first;
		}
		sort(v.begin(), v.end(), comp);
		int totalweight = 0;
		int totalvalue = 0;
		int index = 0;
		while (totalweight != maxweight)
		{
			int tmp = maxweight - totalweight;
			if (tmp >= v[index].first)
			{
				totalweight = totalweight + v[index].first;
				totalvalue = totalvalue + v[index].first * v[index].second;
			}
			else
			{
				totalweight = totalweight + tmp;
				totalvalue = totalvalue + v[index].second * tmp;
			}
			index++;
		}
		cout << totalvalue << '\n';
		testcase--;
	}
}