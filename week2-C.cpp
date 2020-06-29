#include<iostream>
#include<string>
using namespace std;
int cntS[58];
int cntR[58];
void Init()
{
	for (int i = 0; i < 58; i++)
	{
		cntR[i] = 0;
		cntS[i] = 0;
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
		string S;
		string R;
		cin >> S >> R;
		Init();
		for (int i = 0; i < R.length(); i++)
		{
			cntR[R[i] - 65]++;
		}
		int startindex = 0;
		int endindex = 0;
		int minlength = S.length() + 1;
		int cnt = 0;
		while (endindex <= S.length() - 1)
		{
			cntS[S[endindex] - 65]++;
			if (cntS[S[endindex] - 65] <= cntR[S[endindex] - 65])
			{
				cnt++;
			}
			while (R.length() == cnt)
			{
				if (minlength > endindex - startindex + 1)
				{
					minlength = endindex - startindex + 1;
				}
				if (cntS[S[startindex] - 65] <= cntR[S[startindex] - 65])
				{
					cnt--;
				}
				cntS[S[startindex] - 65]--;
				startindex++;
			}
			endindex++;
		}
		if (minlength == S.length() + 1)
		{
			cout << "0" << '\n';
		}
		else
		{
			cout << minlength << '\n';
		}
		testcase--;
	}
	return 0;
}