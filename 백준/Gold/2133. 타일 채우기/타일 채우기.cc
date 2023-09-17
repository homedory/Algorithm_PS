#include <iostream>
using namespace std;

int main()
{
	int N;
	int dp[35] = { 0 };
	
	cin >> N;

	dp[0] = 1;
	for (int i = 2; i <= N; i++) {
		int cnt = 0;
		
		cnt += 3 * dp[i - 2];

		for (int j = i - 4; j >= 0; j -= 2) {
			cnt += 2 * dp[j];
		}

		dp[i] = cnt;
	}

	cout << dp[N];
}