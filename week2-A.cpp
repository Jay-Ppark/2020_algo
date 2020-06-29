#include<iostream>
#include<string>
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
		int alphacnt;
		int alphalength;
		cin >> alphacnt >> alphalength;
		vector<pair<string, int>> v;
		for (int i = 0; i < alphacnt; i++)
		{
			string tmp;
			cin >> tmp;
			v.push_back({ tmp,0 });
		}
		int totallength;
		string totalcode;
		cin >> totallength >> totalcode;
		for (int i = 0; i < totallength; i++)
		{
			for (int j = 0; j < alphacnt; j++)
			{
				int index = i;
				if (i >= alphalength)
				{
					index = i % alphalength;
				}
				if (totalcode[i] - v[j].first[index] != 0)
				{
					v[j].second++;
				}
			}
			if ((i+1) % alphalength == 0)
			{
				int minindex = 0;
				int mintmp = v[0].second;
				v[0].second = 0;
				for (int j = 1; j < alphacnt; j++)
				{
					if (mintmp > v[j].second)
					{
						minindex = j;
						mintmp = v[j].second;
					}
					v[j].second = 0;
				}
				cout << char(minindex + 65);
			}
		}
		cout << '\n';
		testcase--;
	}
	return 0;
}