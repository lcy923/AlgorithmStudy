#include <iostream>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool check[51][51] = { false };
int arr[51][51];
int n, m, k;

void reset()
{
	for (int i = 0; i <= 50; i++)
	{
		for (int j = 0; j <= 50; j++)
		{
			check[i][j] = false;
			arr[i][j] = 0;
		}
	}
}

void dfs(int x, int y)
{
	if (check[x][y])
		return;
	check[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (arr[nx][ny] == 0)
			continue;

		dfs(nx, ny);
	}
}

int main(void)
{

	int t;
	cin >> t;

	for (int z = 0; z < t; z++)
	{
		reset();
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		int result = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!check[i][j] && arr[i][j] == 1)
				{
					result++;
					dfs(i, j);
				}
			}
		}

		cout << result << "\n";
	}

	return 0;
}