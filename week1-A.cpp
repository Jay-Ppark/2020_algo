#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int dna[4][1000];
bool comp(pair<char, int> a, pair<char, int> b)
{
	if (a.second > b.second)
	{
		return true;
	}
	else
	{
		if (a.second < b.second)
		{
			return false;
		}
		else
		{
			if (a.first < b.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
void initarr()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			dna[i][j] = 0;
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
		int species;
		int dnalength;
		cin >> species >> dnalength;
		initarr();
		for (int i = 0; i < species; i++)
		{
			string tmp;
			cin >> tmp;
			for (int j = 0; j < dnalength; j++)
			{
				if (tmp[j] == 'A')
				{
					dna[0][j]++;
				}
				else if (tmp[j] == 'C')
				{
					dna[1][j]++;
				}
				else if (tmp[j] == 'G')
				{
					dna[2][j]++;
				}
				else
				{
					dna[3][j]++;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < dnalength; i++)
		{
			vector<pair<char, int>> v;
			v.push_back({ 'A', dna[0][i] });
			v.push_back({ 'C',dna[1][i] });
			v.push_back({ 'G',dna[2][i] });
			v.push_back({ 'T',dna[3][i] });
			sort(v.begin(), v.end(), comp);
			sum = sum + species - v[0].second;
			cout << v[0].first;
		}
		cout << '\n' << sum << '\n';
		testcase--;
	}
	return 0;
}