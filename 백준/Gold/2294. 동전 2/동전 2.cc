#include <iostream>
#include <vector>
using namespace std;

#define INF 2000000000

int main()
{
	int n, k;
	int dp[10005];
	vector <int> coins;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		coins.push_back(c);
	}

	//initialize
	for (int i = 1; i <= k; i++) {
		dp[i] = INF;
	}
	dp[0] = 0;

	
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (coins[j] <= i) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}

	if (dp[k] == INF) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
}