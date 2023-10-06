#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int visit[55][55];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void init()
{
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visit[i][j] = 0;
		}
	}
}

int main()
{
	int N, L, R, day = 0;
	int A[55][55];
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	bool flag = true;
	while (flag) {
		init();

		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j])
					continue;

				queue <pair<int, int>> q;
				vector <pair<int, int>> visited_point;
				int sum = 0;

				q.push({ i, j });
				visited_point.push_back({ i, j });
				visit[i][j] = 1;

				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();

					sum += A[x][y];
					
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == 0 ) {
							if (abs(A[x][y] - A[nx][ny]) >= L && abs(A[x][y] - A[nx][ny]) <= R) {
								visit[nx][ny] = 1;
								q.push({ nx, ny });
								visited_point.push_back({ nx,ny });
							}
						}
					}
				}

				int mean = sum / visited_point.size();

				for (auto e : visited_point) {
					A[e.first][e.second] = mean;
				}

				if (visited_point.size() > 1) {
					flag = true;
				}
			}
		}

		if (flag) 
			day++;
	}

	cout << day;
}