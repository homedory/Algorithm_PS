#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define INF 2000000000;

int main()
{
	int n, m, k;
	vector <pair<int, int>> path[1005]; //<to, distance>
	priority_queue <int> dist_in_order[1005];
	priority_queue <pair<int, int>> pq;
	int dist[1005];

	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		path[a].push_back({ b, c });
	}

	//initialize
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int now_dist = -pq.top().first, now = pq.top().second;
		pq.pop();

		// put distances until the size is k to calculate 'k'th distance
		if (dist_in_order[now].size() < k) {
			dist_in_order[now].push(now_dist);
		}
		else {
			continue;
		}

		for (auto e : path[now]) {
			int to = e.first, d = now_dist + e.second;
			pq.push({ -d, to });
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist_in_order[i].size() == k) {
			cout << dist_in_order[i].top() << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
}