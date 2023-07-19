#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[10][10];
int visit[10][10];
int N, M;

int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0 , 1, -1 };


void init()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}

int main()
{
	vector <pair<int, int>> zeros, twos;
	cin >> N >> M;
	int minCnt = 100;
	int zeroNum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				zeros.push_back(make_pair(i, j));
				zeroNum++;
			}
			else if (arr[i][j] == 2) {
				twos.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < zeros.size(); i++) {
		for (int j = i + 1; j < zeros.size(); j++) {
			for (int k = j + 1; k < zeros.size(); k++) {
				queue <pair<int, int>> q;
				int cnt = 0;
				init();

				for (int l = 0; l < twos.size(); l++) {
					q.push(make_pair(twos[l].first, twos[l].second));
					visit[twos[l].first][twos[l].second] = 1;
				}

				arr[zeros[i].first][zeros[i].second] = 1;
				arr[zeros[j].first][zeros[j].second] = 1;
				arr[zeros[k].first][zeros[k].second] = 1;

				while (!q.empty()) {
					int a = q.front().first, b = q.front().second;
					q.pop();
					for (int l = 0; l < 4; l++) {
						int na = a + x[l];
						int nb = b + y[l];
						if (na >= 0 && na < N && nb >= 0 && nb < M && arr[na][nb] == 0 && visit[na][nb] == 0) {
							q.push(make_pair(na, nb));
							visit[na][nb] = 1;
							cnt++;
						}
					}
				}

				minCnt = min(minCnt, cnt);

				arr[zeros[i].first][zeros[i].second] = 0;
				arr[zeros[j].first][zeros[j].second] = 0;
				arr[zeros[k].first][zeros[k].second] = 0;
			}
		}
	}
	cout << zeroNum - 3 - minCnt;

}