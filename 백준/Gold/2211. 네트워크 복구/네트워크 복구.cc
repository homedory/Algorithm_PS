#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2000000000;


int main()
{
	int N, M;
	priority_queue<pair<int, pair<int, int>>> pq;
	vector <pair<int, int>> edges[1005];
	int dist[1005];
	int prev[1005];

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}

	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}

	dist[1] = 0;
	for (int i = 0; i < edges[1].size(); i++) {
		pq.push(make_pair(-edges[1][i].second, make_pair(edges[1][i].first, 1)));
	}

	while (!pq.empty()) {
		int d = -pq.top().first, now = pq.top().second.first, from = pq.top().second.second;
		pq.pop();

		if (d < dist[now]) {
			dist[now] = d;
			prev[now] = from;
			for (int i = 0; i < edges[now].size(); i++) {
				pq.push(make_pair(-(edges[now][i].second + d), make_pair(edges[now][i].first, now)));
			}
		}
	}

	cout << N - 1 << "\n";
	for (int i = 2; i <= N; i++) {
		cout << prev[i] << " " << i << "\n";
	}
}