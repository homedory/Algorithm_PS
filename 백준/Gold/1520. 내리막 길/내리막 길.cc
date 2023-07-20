#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[505][505];
int H[505][505];
int _x[4] = { -1, 1, 0, 0 };
int _y[4] = { 0, 0 ,-1, 1 };

int main()
{
	int N, M;
	priority_queue <pair<int, pair<int, int>>> pq;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> H[i][j];
			pq.push(make_pair(H[i][j], make_pair(i, j)));
		}
	}

	dp[0][0] = 1;

	while (!pq.empty()) {
		int h = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + _x[i];
			int ny = y + _y[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && H[nx][ny] > h) {
				dp[x][y] += dp[nx][ny];
			}
		}
		pq.pop();
	}
	cout << dp[N - 1][M - 1];
}