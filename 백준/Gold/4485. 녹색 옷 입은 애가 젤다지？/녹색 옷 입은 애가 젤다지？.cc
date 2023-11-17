#include <iostream>\
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000

int d[130][130];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = INF;
		}
	}
}

int main()
{
	int N, T = 1;
	int map[130][130];

	while (1) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		init(N);

		priority_queue < pair<int, pair<int, int>>> pq;

		pq.push({ -map[0][0], {0,0} });
		while (!pq.empty()) {
			int c = -pq.top().first;
			int x = pq.top().second.first, y = pq.top().second.second;
			pq.pop();

			if (d[x][y] != INF) {
				continue;
			}

			d[x][y] = c;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] + c < d[nx][ny]) {
						pq.push({ -(c + map[nx][ny]), {nx,ny} });
					}
				}
			}
		}
		cout << "Problem " << T << ": " << d[N - 1][N - 1] << "\n";
		T++;
	}

}