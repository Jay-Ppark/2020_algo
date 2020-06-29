#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int num[9];
bool visited[9];
int N;
int leftnum;
int rightnum;
int mulnum;
int result;
vector<int> v;
void Init()
{
	for (int i = 0; i < 9; i++)
	{
		num[i] = 0;
		visited[i] = false;
	}
}
void solve(int cnt)
{
	if (cnt == N)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int tmp = pow(mulnum, N - i - 1);
			tmp = tmp % 1013;
			sum = sum + tmp * v[i];
			sum = sum % 1013;
		}
		if (sum >= leftnum && sum <= rightnum)
		{
			result++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			v.push_back(num[i]);
			visited[i] = true;
			solve(cnt + 1);
			v.pop_back();
			visited[i] = false;
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
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num[i];
		}
		cin >> leftnum >> rightnum >> mulnum;
		solve(0);
		cout << result << '\n';
		v.clear();
		Init();
		result = 0;
		testcase--;
	}
	return 0;
}