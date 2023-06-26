#include <iostream>
using namespace std;
#include <queue>

int n;
priority_queue<int, vector<int>, greater<int>> q;

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int card;
		cin >> card;
		q.push(card);
	}

	int result = 0;

	if (q.size() == 1)
	{
		cout << 0;
		return 0;
	}

	while (q.size() != 1)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		result += (a + b);
		q.push(a + b);
	}

	cout << result;

	return 0;
}