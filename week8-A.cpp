#include<iostream>
using namespace std;
int slot[102];
int score[102];
void Init()
{
	for (int i = 0; i <= 100; i++)
	{
		slot[i] = 0;
		score[i] = 0;
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
		int slotnum;
		int numrange;
		cin >> slotnum >> numrange;
		for (int i = 1; i <= slotnum; i++)
		{
			cin >> score[i];
		}
		for (int i = 0; i < slotnum; i++)
		{
			int num;
			int slotindex;
			cin >> num >> slotindex;
			slot[slotindex] = num;
		}
		int cnt = 1;
		int sum = 0;
		for (int i = 1; i <= slotnum; i++)
		{
			if (slot[i] < slot[i + 1])
			{
				cnt++;
			}
			else
			{
				sum = sum + score[cnt];
				cnt = 1;
			}
		}
		cout << sum << '\n';
		Init();
		testcase--;
	}
	return 0;
}