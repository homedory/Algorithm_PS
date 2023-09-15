#include <iostream>
#include <string>
using namespace std;

int dp[1005][1005];

int main()
{
	string a, b;

	cin >> a;
	cin >> b;

	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	cout << dp[a.length()][b.length()];

}