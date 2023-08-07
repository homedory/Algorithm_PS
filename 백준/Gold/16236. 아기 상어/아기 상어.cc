#include <iostream>
#include <queue>

using namespace std;

int m[21][21];
int N;
int x_start, y_start;

int bfs(int X, int Y, int size)
{
	int x_move[4] = { -1, 0, 0, 1 };
	int y_move[4] = { 0, -1, 1, 0 };
	int visit[21][21] = { 0 };
	int d[21][21] = { 0 };
	queue <pair<int, int>> q;
	int dist = 0;
	bool flag = true;

	q.push(make_pair(X, Y));
	visit[X][Y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (!flag && d[x][y] == dist) break;

		for (int i = 0; i < 4; i++) {
			int nx = x + x_move[i];
			int ny = y + y_move[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == 0 && m[nx][ny] <= size) {
				d[nx][ny] = d[x][y] + 1;
				if (m[nx][ny] < size && m[nx][ny] > 0) {
					if (!flag && x_start > nx) {
						x_start = nx;
						y_start = ny;
					}
					else if (!flag && x_start == nx && y_start > ny) {
						y_start = ny;
					}
					else if (flag) {
						x_start = nx;
						y_start = ny;
					}
					
					dist = d[nx][ny];
					flag = false;
				}
				else {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return dist;
}

int main()
{
	int ans = 0;
	int size = 2;
	int cnt = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			if (m[i][j] == 9) {
				x_start = i;
				y_start = j;
				m[i][j] = 0;
			}
		}
	}

	while (1) {
		int d = bfs(x_start, y_start, size);
		ans += d;
		
		if (d == 0) break;
		else {
			m[x_start][y_start] = 0;
			cnt++;
			if (cnt == size) {
				cnt = 0;
				size++;
			}
		}
	}

	cout << ans;
}
