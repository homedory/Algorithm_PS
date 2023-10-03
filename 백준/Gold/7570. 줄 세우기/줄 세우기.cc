#include <iostream>
#include <vector>
using namespace std;

int dp[1000005];

int main()
{
	int N, ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		dp[x] = dp[x - 1] + 1;
		ans = max(ans, dp[x]);
	}

	cout << N - ans;
}