#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

#define INF 200000000

int h_move[4] = { -1, 1, 0, 0 };
int w_move[4] = { 0, 0, -1, 1 };

int h, w;
char floor_map[105][105];

int dist[3][105][105];

void shortest_path(int x, int y, int n) // (x,y)->start , n = 0,1,2
{
	deque <pair<int, pair<int, int>>> dq; //<dist, <x,y>>

	dq.push_front({ 0, {x, y} });
	//dist[n][x][y] = 0;

	while (!dq.empty()) {
		int now_dist = dq.front().first, now_h = dq.front().second.first, now_w = dq.front().second.second;
		dq.pop_front();

		if (dist[n][now_h][now_w] <= now_dist)
			continue;

		dist[n][now_h][now_w] = now_dist;

		for (int i = 0; i < 4; i++) {
			int next_h = now_h + h_move[i];
			int next_w = now_w + w_move[i];

			if (next_h <= h + 1 && next_h >= 0 && next_w <= w + 1 && next_w >= 0) {

				if (floor_map[next_h][next_w] == '#') {
					if (dist[n][next_h][next_w] > now_dist + 1) {
						//dist[n][next_h][next_w] = now_dist + 1;
						dq.push_back({ now_dist + 1, {next_h, next_w} });
					}
				}
				else if (floor_map[next_h][next_w] == '.' || floor_map[next_h][next_w] == '$') {
					if (dist[n][next_h][next_w] > now_dist) {
						//dist[n][next_h][next_w] = now_dist;
						dq.push_front({ now_dist, {next_h, next_w} });
					}
				}
			}
		}
	}
}


void init()
{
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			dist[0][i][j] = INF;
			dist[1][i][j] = INF;
			dist[2][i][j] = INF;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		vector<pair<int, int>> start;
		
		//initialize
		init();

		cin >> h >> w;

		//input map
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> floor_map[i][j];
				
				//find start points
				if (floor_map[i][j] == '$') {
					start.push_back({ i, j });
				}
			}
		}

		//padding map
		for (int i = 0; i <= h + 1; i++) {
			if (i == 0 || i == h + 1) {
				for (int j = 0; j <= w + 1; j++) {
					floor_map[i][j] = '.';
				}
			}
			floor_map[i][0] = '.';
			floor_map[i][w+1] = '.';
		}

		
		
		//start from outside
		shortest_path(0, 0, 0);
		//start from start1 point
		shortest_path(start[0].first, start[0].second, 1);
		//start from start2 point
		shortest_path(start[1].first, start[1].second, 2);

		int ans = INF;

		//find meeting point of 3 starts
		for (int i = 1; i <= h; i++) { 
			for (int j = 1; j <= w; j++) {
				if (floor_map[i][j] == '*')
					continue;
				
				int sum = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];

				if (floor_map[i][j] == '#')
					sum -= 2;
				
				ans = min(ans, sum);
			}

		}
		
		cout << ans << "\n";
	}
}