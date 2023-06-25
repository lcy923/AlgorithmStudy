#include <iostream>
using namespace std;
#include <vector>

bool check[50] = { false };

void reset()
{
	for (int i = 1; i <= 49; i++)
		check[i] = false;
}

void dfs(int index, vector<int> v, vector<int> list)
{
	if (list.size() == 6)
	{
		for (int i = 0; i < list.size(); i++)
			cout << list[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = index; i < v.size(); i++)
	{
		if (!check[i])
		{
			check[i] = true;
			list.push_back(v[i]);
			dfs(i, v, list);
			list.erase(--list.end());
			check[i] = false;
		}
	}
}

int main(void)
{
	
	while (true)
	{
		vector<int> v;
		reset();
		int t;

		cin >> t;

		if (t == 0)
			break;

		for (int i = 0; i < t; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}

		vector<int> list;
		dfs(0, v, list);
		cout << "\n";
	}

	return 0;
}