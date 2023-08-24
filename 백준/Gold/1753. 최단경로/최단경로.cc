#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 200000
int d[20010];
vector <pair<int, int>> Edge[20010];
priority_queue<pair<int, int>> q;

void dijk(int start)
{
    q.push({0, start});
    
	while (!q.empty()) {
		int now, nowdist;
		nowdist = -q.top().first;
		now = q.top().second;
		q.pop();

		if (d[now] != INF)
			continue;

		d[now] = nowdist;
		for (auto e : Edge[now]) {
			if (d[e.first] == INF) {
				q.push({ -(nowdist + e.second), e.first });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int V, E, K;
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		Edge[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}
	dijk(K);
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << d[i] << "\n";
		}
	}
}