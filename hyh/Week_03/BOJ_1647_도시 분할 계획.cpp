#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n, m;
vector<pair<int, int>> v[100001];
bool check[100001] = { false };

long long int result = 0;
int maxCost = 0;

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
		maxCost = max(ccost, maxCost);

		for (int i = 0; i < v[cx].size(); i++)
		{
			int nx = v[cx][i].first;
			int ncost = v[cx][i].second;
			q.push(make_pair(ncost, nx));
		}

	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
		v[to].push_back(make_pair(from, cost));
	}

	MST();
	cout << result - maxCost;

	return 0;
}