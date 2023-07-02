#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int v, e;
bool check[10001] = { false };

vector<pair<int, int>> vec[10001];

long long int result = 0;

void MST()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, 1));

	while (!q.empty())
	{
		int cx = q.top().second;
		int ccost = q.top().first;
		q.pop();

		if (check[cx])
			continue;
		check[cx] = true;
		result += ccost;

		for (int i = 0; i < vec[cx].size(); i++)
		{
			int nx = vec[cx][i].first;
			int ncost = vec[cx][i].second;

			q.push(make_pair(ncost, nx));
		}
	}
}

int main(void)
{
	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		vec[from].push_back(make_pair(to, cost));
		vec[to].push_back(make_pair(from, cost));
	}

	MST();
	cout << result;

	return 0;
}