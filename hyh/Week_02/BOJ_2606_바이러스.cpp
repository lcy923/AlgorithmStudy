#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <algorithm>

int n, m;
vector<int> v[101];
bool check[101] = { false };

void reset()
{
	for (int i = 1; i <= n; i++)
		check[i] = false;
}

void dfs(int x)
{
	if (check[x])
		return;
	check[x] = true;

	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		dfs(next);
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	dfs(1);

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i])
			result++;
	}

	cout << result - 1;

	return 0;
}