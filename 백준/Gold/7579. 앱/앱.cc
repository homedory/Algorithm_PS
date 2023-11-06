#include <iostream>
using namespace std;

int dp[105][10005];

int main()
{
	int N, M;
	int c[105], m[105];

	cin >> N >> M;

	
	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10005; j++) {
			if (c[i] <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i < 10005; i++) {
		if (dp[N][i] >= M) {
			cout << i;
			break;
		}
	}
}