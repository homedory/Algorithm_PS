#include <iostream> 
#include <algorithm>
using namespace std;

char arr[1005][1005];
int dp[1005][1005];

int main()
{
	int n, m, max_len = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '0') 
				continue;

			dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

			max_len = max(max_len, dp[i][j]);
		}
	}

	cout << max_len * max_len;
}