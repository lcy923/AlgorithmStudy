#include <iostream>
using namespace std;
#include <math.h>

int n, r, c;
int result = 0;

void dfs(int len, int x, int y)
{
	if (x == r && y == c)
	{
		cout << result;
		return;
	}

	if (x <= r && r < x + len && y <= c && c < y + len)
	{
		dfs(len / 2, x, y);
		dfs(len / 2, x, y + len / 2);
		dfs(len / 2, x + len / 2, y);
		dfs(len / 2, x + len / 2, y + len / 2);
	}
	else
	{
		result += len * len;
		return;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r >> c;

	int len = pow(2, n);

	dfs(len, 0, 0);

	return 0;
}