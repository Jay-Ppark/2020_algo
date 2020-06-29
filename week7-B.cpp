#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct kruskal
{
	int from;
	int to;
	int value;
};
vector<kruskal> v;
bool check;
int parent[1001];
int find(int u)
{
	if (u == parent[u])
	{
		return u;
	}
	return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
	check = false;
	u = find(u);
	v = find(v);
	if (u == v)
	{
		return;
	}
	parent[u] = v;
	check = true;
}
bool comp(kruskal a, kruskal b)
{
	return a.value < b.value;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase > 0)
	{
		kruskal t;
		int itemnum;
		cin >> itemnum;
		int pricesum = 0;
		for (int i = 0; i < itemnum; i++)
		{
			int itemprice;
			int packprice;
			cin >> itemprice >> packprice;
			if (i == 0)
			{
				t.from = 0;
				t.to = i + 1;
				t.value = itemprice;
				v.push_back(t);
			}
			else
			{
				t.from = 0;
				t.to = i + 1;
				t.value = itemprice;
				v.push_back(t);
				t.from = i;
				t.to = i + 1;
				t.value = packprice;
				v.push_back(t);
			}
			pricesum = pricesum + itemprice;
		}
		sort(v.begin(), v.end(), comp);
		for (int i = 0; i <= itemnum; i++)
		{
			parent[i] = i;
		}
		for (int i = 0; i < v.size(); i++)
		{
			merge(v[i].from, v[i].to);
			if (check)
			{
				pricesum = pricesum + v[i].value;
			}
		}
		cout << pricesum << '\n';
		v.clear();
		testcase--;
	}
	return 0;
}