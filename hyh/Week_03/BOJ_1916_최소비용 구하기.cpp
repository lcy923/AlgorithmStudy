#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n, m;
vector<pair<int, int>> v[1001];
int d[1001];

int start, finish;

void da(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	d[start] = 0;
	q.push(make_pair(0, start));

	while (!q.empty())
	{
		int cx = q.top().second;
		int cost = q.top().first;
		q.pop();

		if (d[cx] > cost)
			continue;
		d[cx] = cost;

		if (cx == finish)
		{
			cout << cost;
			break;
		}

		for (int i = 0; i < v[cx].size(); i++)
		{
			int nx = v[cx][i].first;
			int ncost = v[cx][i].second;

			if (d[nx] > ncost + d[cx])
			{
				d[nx] = ncost + d[cx];
				q.push(make_pair(d[nx], nx));
			}

		}
	}
}

void reset()
{
	for (int i = 1; i <= n; i++)
		d[i] = 987654321;
}

int main(void)
{
	cin >> n >> m;

	reset();

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
	}

	cin >> start >> finish;

	da(start);

	return 0;
}