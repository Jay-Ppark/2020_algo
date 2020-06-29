#include<iostream>
#include<vector>
using namespace std;
int num[8];
bool ismul[7];
int exnum;
int neednum;
bool makenum;
int resultnum;
void Init()
{
	for (int i = 0; i < 8; i++)
	{
		num[i] = 0;
		if (i != 7)
		{
			ismul[i] = false;
		}
	}
}
void solve(int start)
{
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < neednum; i++)
	{
		v.push_back(num[i]);
		if (i != neednum - 1)
		{
			if (ismul[i])
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(-2);
			}
		}
	}
	vector<int>::iterator viter;
	for (viter = v.begin(); viter != v.end();)
	{
		if (*viter == -1)
		{
			*viter = *(viter - 1) * (*(viter + 1));
			viter = v.erase(viter - 1);
			viter = v.erase(viter + 1);
		}
		else
		{
			viter++;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != -2)
		{
			sum = sum + v[i];
		}
	}
	v.clear();
	if (sum == resultnum)
	{
		makenum = true;
	}
	for (int i = start; i < neednum - 1 ; i++)
	{
		if (!ismul[i])
		{
			ismul[i] = true;
			solve(i);
			ismul[i] = false;
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
		cin >> exnum >> neednum;
		while (exnum > 0)
		{
			for (int i = 0; i < neednum; i++)
			{
				cin >> num[i];
			}
			cin >> resultnum;
			solve(0);
			if (makenum)
			{
				cout << "1" << " ";
			}
			else
			{
				cout << "0" << " ";
			}
			Init();
			makenum = false;
			exnum--;
		}
		cout << '\n';
		testcase--;
	}
	return 0;
}