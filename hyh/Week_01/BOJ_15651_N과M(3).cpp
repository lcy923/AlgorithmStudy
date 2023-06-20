#include <iostream>
using namespace std;
#include <vector>

int n, m;

void dfs(vector<int> count)
{
	if (count.size() == m)
	{
		for (int i = 0; i < count.size(); i++)
			cout << count[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		count.push_back(i);
		dfs(count);
		count.erase(--count.end());
	}
}

int main(void)
{
	cin >> n >> m;

	vector<int> count;
	dfs(count);

	return 0;
}