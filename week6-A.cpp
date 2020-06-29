#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		string s;
		int tmp = 0;
		int div;
		cin >> s >> div;
		for (int i = 0; i < s.length(); i++)
		{
			if (tmp < div)
			{
				tmp = tmp * 10;
				tmp = tmp + (s[i] - '0');
			}
			else
			{
				tmp = tmp % div;
				tmp = tmp * 10;
				tmp = tmp + (s[i] - '0');
			}
		}
		if (tmp % div == 0)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
		testcase--;
	}
	return 0;
}