#include <iostream>
using namespace std;
#include <vector>

int n, m;
vector<int> card;
int result = 0;
bool check[101] = { false };

void dfs(int sum, int count, int index)
{
	if (count == 3)
	{
		if (sum <= m)
			result = max(result, sum);

		return;
	}

	for (int i = index; i < card.size(); i++)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(sum + card[i], count + 1, index + 1);
			check[i] = false;
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		card.push_back(num);
	}

	dfs(0, 0, 0);

	cout << result;

	return 0;
}