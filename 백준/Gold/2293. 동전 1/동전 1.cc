#include <iostream>
using namespace std;

int coin[105], dp[10005];

int main()
{
	int N, K;
	
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			if (coin[i] <= j) {
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
	}
		
	cout << dp[K];
}