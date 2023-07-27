#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2000000000

int N;
int dp[(1 << 16)][16];
int w[20][20];  

void init() {
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < 16; j++) {
			dp[i][j] = -1;
		}
	}
}

int TSP(int visited, int now)
{
	if (visited == (1 << N) - 1) {
		if (w[now][0] > 0) {
			return w[now][0];
		}
		else {
			return INF;
		}
	}

	if (dp[visited][now] != -1) {
		return dp[visited][now];
	}
	else {
		dp[visited][now] = INF;
		for (int i = 0; i < N; i++) {
			if (!(visited & (1 << i)) && w[now][i] > 0) {
				dp[visited][now] = min(dp[visited][now], TSP(visited | (1 << i), i) + w[now][i]);
			}
		}
		return dp[visited][now];
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}

	init();
	cout << TSP(1, 0);
}