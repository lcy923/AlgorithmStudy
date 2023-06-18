#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<int> v;
bool check[9] = { false };
bool print = false;

void dfs(int index, vector<int> list)
{
	if (list.size() == 7)
	{
		int sum = 0;
		for (int i = 0; i < list.size(); i++)
			sum += list[i];

		if (sum == 100)
		{
			if (!print)
			{
				sort(list.begin(), list.end());
				for (int i = 0; i < list.size(); i++)
					cout << list[i] << "\n";
				
				print = true;
			}
		}

		

		return;
	}

	for (int i = index; i < v.size(); i++)
	{
		if (!check[i])
		{
			check[i] = true;
			list.push_back(v[i]);
			dfs(i + 1, list);
			list.erase(--list.end());
			check[i] = false;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		int height;
		cin >> height;
		v.push_back(height);
	}

	vector<int> list;
	dfs(0, list);

	return 0;
}