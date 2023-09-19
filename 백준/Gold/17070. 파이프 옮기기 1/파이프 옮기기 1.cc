#include <iostream>
using namespace std;

int horiz_dp[20][20], diag_dp[20][20], vertic_dp[20][20];
int house[20][20];

int main()
{
	int N;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> house[i][j];
		}
	}

	horiz_dp[1][2] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (house[i][j] == 1) continue;

			//horizontal
			horiz_dp[i][j] += horiz_dp[i][j - 1] + diag_dp[i][j - 1];
			
			//vertical
			vertic_dp[i][j] += vertic_dp[i - 1][j] + diag_dp[i - 1][j];

			//diagonal
			if (house[i - 1][j] == 0 && house[i][j - 1] == 0) {
				diag_dp[i][j] += horiz_dp[i - 1][j - 1] + vertic_dp[i - 1][j - 1] + diag_dp[i - 1][j - 1];
			}
		}
	}

	cout << diag_dp[N][N] + vertic_dp[N][N] + horiz_dp[N][N];
}