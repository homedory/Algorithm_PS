#include <iostream>
#include <queue>
using namespace std;

priority_queue < pair<int, pair<int, int>>> pq;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int arr[505][505], dp[505][505];

int main()
{
	int N, ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			pq.push({ -arr[i][j], {i, j} });
		}
	}

	while (!pq.empty()) {
		int max_num = 0;
		int w = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] < w) {
				max_num = max(max_num, dp[nx][ny]);
			}
		}
		
		dp[x][y] = max_num + 1;

		ans = max(ans, dp[x][y]);
	}

	cout << ans;
}