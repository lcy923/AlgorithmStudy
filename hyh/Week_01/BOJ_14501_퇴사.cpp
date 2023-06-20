#include <iostream>
using namespace std;

int n;
int t[16], p[16];
int dp[16];

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	for (int i = n; i >= 1; i--)
	{
		int day = t[i] + i - 1;

		if (day > n)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], p[i] + dp[day + 1]);
	}

	cout << dp[1];

	return 0;
}