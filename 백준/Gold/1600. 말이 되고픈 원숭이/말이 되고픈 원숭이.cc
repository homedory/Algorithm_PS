#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 2000000000

int K, H ,W;
int arr[205][205], visit[35][205][205];
int horse_h[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int horse_w[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int monkey_h[4] = { -1, 1, 0 , 0 };
int monkey_w[4] = { 0, 0 , -1 ,1 };


int main()
{
	int ans = -1;
	queue < pair<pair<int, int>, pair<int, int>>> q; //<<h,w>, <k, movement_cnt>>
	
	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}

	q.push({ {0,0},{0,0} });
	visit[0][0][0] = 1;

	while (!q.empty()) {
		int h = q.front().first.first, w = q.front().first.second;
		int k = q.front().second.first, movement_cnt = q.front().second.second;

		q.pop();


		if (h == H - 1 && w == W - 1) {
			ans = movement_cnt;
			break;
		}

		//monkey_movement
		for (int i = 0; i < 4; i++) {
			int nh = h + monkey_h[i];
			int nw = w + monkey_w[i];

			if (nh >= 0 && nh < H && nw >= 0 && nw < W && arr[nh][nw] == 0 && visit[k][nh][nw] == 0) {
				q.push({ {nh, nw}, {k, movement_cnt + 1} });
				visit[k][nh][nw] = 1;
			}
		}

		if (k >= K)
			continue;

		//horse_movement
		for (int i = 0; i < 8; i++) {
			int nh = h + horse_h[i];
			int nw = w + horse_w[i];

			if (nh >= 0 && nh < H && nw >= 0 && nw < W && arr[nh][nw] == 0 && visit[k+1][nh][nw] == 0) {
				q.push({ {nh, nw}, {k + 1, movement_cnt + 1} });
				visit[k + 1][nh][nw] = 1;
			}
		}

	}
	
	cout << ans;
}