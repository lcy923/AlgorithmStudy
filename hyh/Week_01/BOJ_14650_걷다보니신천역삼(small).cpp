#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int n;
int result = 0;

void dfs(string s)
{
	if (s.size() == n)
	{
		if (s[0] != '0')
		{
			int sum = 0;
			for (int i = 0; i < s.size(); i++)
				sum += s[i] - '0';

			if (sum % 3 == 0)
				result++;
		}

		return;
	}

	for (int i = 0; i <= 2; i++)
	{
		s += to_string(i);
		dfs(s);
		s = s.substr(0, s.size() - 1);
	}
}

int main(void)
{
	cin >> n;

	string s = "";
	dfs(s);

	cout << result;

	return 0;
}