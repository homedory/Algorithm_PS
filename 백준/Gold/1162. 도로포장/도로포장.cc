#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
	dp + dijkstra
*/

long long dp[10005][25];								  //dp[city][paved] = least_time

int main()
{
	int N, M, K;
	priority_queue<pair<long long, pair<int, int>>> pq;  //<total_time,<paved_num, city>>
	vector<pair<int, int>> path[10005];					 //<to, time>


	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		path[start].push_back(make_pair(end, time));
		path[end].push_back(make_pair(start, time));
	}

	//initiailize
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = -1;
		}
	}

	pq.push(make_pair(0, make_pair(0, 1)));

	while (!pq.empty()) {
		long long now_time = -pq.top().first;
		int paved_num = pq.top().second.first, now = pq.top().second.second;
		pq.pop();
		
		if (dp[now][paved_num] > 0) continue;

		dp[now][paved_num] = now_time;

		for (int i = 0; i < path[now].size(); i++) {
			int to = path[now][i].first, time = path[now][i].second;
			
			//pave the road
			if (paved_num < K) { 
				if (dp[to][paved_num + 1] < 0) {
					pq.push(make_pair(-now_time, make_pair(paved_num + 1, to)));
				}
			}
			//not pave the road
			if (dp[to][paved_num] < 0) {
				pq.push(make_pair(-(now_time + time), make_pair(paved_num, to)));
			}
		}
	}

	//find minimum_time
	long long min_time = dp[N][0];
	for (int i = 1; i <= K; i++) {
		if (dp[N][i] != -1 && min_time > dp[N][i])
			min_time = dp[N][i];
	}

	cout << min_time;
}
