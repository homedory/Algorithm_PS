#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, glacier_cnt = 0;
int map[305][305];
int c[305][305];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void simulation(int x, int y) {
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0) {
			c[x][y] += 1;
		}
	}
}

bool is_all_connnected(int x, int y)
{
	int visit[305][305];
	int cnt = 1;
	queue <pair<int, int>> q;

	//initialize
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}

	visit[x][y] = 1;
	q.push({ x,y });

	while (!q.empty()) {
		int sx = q.front().first, sy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] > 0 && visit[nx][ny] == 0) {
				cnt++;
				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}

	}

	if (cnt == glacier_cnt) {
		return true;
	}
	else {
		return false;
	}
	
	
}

int main()
{
	int year = 0;
	
	cin >> N >> M;

	//input
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				glacier_cnt++;
			}
		}
	}

	while (1) {
		year++;
		vector <pair<int, int>> remain_glaciers;

		//calculate hegiht to reduce
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > 0) {
					simulation(i, j);
				}
			}
		}

		//reduce height
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > 0) {
					map[i][j] -= c[i][j];
					c[i][j] = 0;
					if (map[i][j] <= 0) {
						map[i][j] = 0;
						glacier_cnt--;
					}
					else {
						remain_glaciers.push_back({ i, j });
					}
				}
			}
		}

		//no remain glaciers
		if (remain_glaciers.size() == 0) {
			cout << 0;
			break;
		}
		//check if all connected
		else {
			int x = remain_glaciers.front().first;
			int y = remain_glaciers.front().second;
			if (!is_all_connnected(x, y)) {
				cout << year;
				break;
			}
		}

	}
}