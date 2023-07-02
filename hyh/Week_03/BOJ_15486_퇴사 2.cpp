#include <iostream>
using namespace std;

int n;
int t[1500001];
int c[1500001];
int dp[1500001];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> t[i] >> c[i];

	for (int i = n - 1; i >= 0; i--)
	{
		if (i + t[i] - 1 <= n - 1)
		{
			dp[i] = max(dp[i + 1], dp[i + t[i]] + c[i]);
		}
		else
			dp[i] = dp[i + 1];
	}


	cout << dp[0];

	return 0;
}