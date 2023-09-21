#include <iostream>
using namespace std;

int max_dp[2][3], min_dp[2][3], arr[100005][3];

int main()
{
	int N;
	

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	int now, prev;

	for (int i = 1; i <= N; i++) {
		now = i % 2;
		prev = (i - 1) % 2;

		//arr[i][0]
		max_dp[now][0] = max(max_dp[prev][0], max_dp[prev][1]) + arr[i][0];
		min_dp[now][0] = min(min_dp[prev][0], min_dp[prev][1]) + arr[i][0];

		//arr[i][1]
		max_dp[now][1] = max(max_dp[prev][0], max(max_dp[prev][1], max_dp[prev][2])) + arr[i][1];
		min_dp[now][1] = min(min_dp[prev][0], min(min_dp[prev][1], min_dp[prev][2])) + arr[i][1];

		//arr[i][2]
		max_dp[now][2] = max(max_dp[prev][1], max_dp[prev][2]) + arr[i][2];
		min_dp[now][2] = min(min_dp[prev][1], min_dp[prev][2]) + arr[i][2];
	}

	int max_score = max(max_dp[now][0], max(max_dp[now][1], max_dp[now][2]));
	int min_score = min(min_dp[now][0], min(min_dp[now][1], min_dp[now][2]));

	cout << max_score << " " << min_score;
}
