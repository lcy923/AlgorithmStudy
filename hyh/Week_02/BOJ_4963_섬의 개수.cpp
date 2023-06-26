#include <iostream>
using namespace std;

int dx[] = { -1,1,0,0,-1,-1,1,1 };
int dy[] = { 0,0,-1,1,-1,1,-1,1 };

bool check[51][51] = { false };
int arr[51][51];
int n, m;

void reset()
{
	for (int i = 1; i <= 50; i++)
	{
		for (int j = 1; j <= 50; j++)
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

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx <= 0 || nx > m || ny <= 0 || ny > n)
			continue;
		if (arr[nx][ny] == 0)
			continue;

		dfs(nx, ny);
	}
}

int main(void)
{
	while (true)
	{
		reset();
		cin >> n >> m;
		
		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];
		}

		int result = 0;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][j] == 1 && !check[i][j])
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