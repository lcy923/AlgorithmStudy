#include <iostream>
using namespace std;
#include <queue>

int n, k;
int d[100001];

void da(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));
	d[start] = 0;

	while (!q.empty())
	{
		int cx = q.top().second;
		int ccost = q.top().first;
		q.pop();

		if (d[cx] < ccost)
			continue;
		d[cx] = ccost;

		if (cx == k)
		{
			cout << ccost;
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			int nx = cx;
			int ncost = ccost;

			if (i == 0)
			{
				nx = cx - 1;
				ncost = ccost + 1;
			}
			else if (i == 1)
			{
				nx = cx + 1;
				ncost = ccost + 1;
			}
			else
				nx = cx * 2;

			if (nx < 0 || nx > 100000)
				continue;

			if (d[nx] > ncost)
			{
				d[nx] = ncost;
				q.push(make_pair(ncost, nx));
			}
		}
	}
}

void reset()
{
	for (int i = 0; i <= 100000; i++)
		d[i] = 987654321;
}

int main(void)
{
	cin >> n >> k;
	reset();
	da(n);

	return 0;
}