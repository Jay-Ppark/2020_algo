#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool ispal(vector<int>& t)
{
	if (t.size() == 1)
	{
		return true;
	}
	else if (t.size() % 2 == 0)
	{
		for (int i = 0; i < t.size() / 2; i++)
		{
			if (t[i] != t[t.size() - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < t.size() / 2; i++)
		{
			if (t[i] != t[t.size() - i - 1])
			{
				return false;
			}
		}
		return true;
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
		string tmp;
		cin >> tmp;
		vector<int> onlyletter;
		for (int i = 0; i < tmp.length(); i++)
		{
			if ((tmp[i] - 0 >= 65 && tmp[i] - 0 <= 90) || (tmp[i] - 0 >= 97 && tmp[i] - 0 <= 122))
			{
				if (tmp[i] - 0 <= 90)
				{
					onlyletter.push_back(tmp[i] - 0);
				}
				else
				{
					onlyletter.push_back(tmp[i] - 32);
				}
			}
		}
		if (ispal(onlyletter))
		{
			cout << "Yes" << '\n';
		}
		else
		{
			cout << "No" << '\n';
		}
		testcase--;
	}
	return 0;
}