#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <algorithm>

int n, m, start;
vector<int> v[1001];
bool check[1001] = { false };

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
	cout << x << " ";

	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		dfs(next);
	}
}
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	check[x] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << " ";

		for (int i = 0; i < v[curr].size(); i++)
		{
			int next = v[curr][i];
			
			if (!check[next])
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}


	dfs(start);
	cout << "\n";
	reset();
	bfs(start);

	return 0;
}