#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define INF 2000000000

int n, m;
vector <pair<int, int>> path[100005];	//<to, cost>
int from[100005], dist[100005];

void dijkstra(int start, int end)
{
	priority_queue <pair<int, int>> pq;
	
	dist[start] = 0;
	pq.push({ 0, start });

	while(!pq.empty()) {
		int now_dist = -pq.top().first, now = pq.top().second;
		pq.pop();

		if (dist[now] < now_dist)
			continue;

		for (auto e : path[now]) {
			int next = e.first;
			int d = now_dist + e.second;
				
			if (dist[next] > d) {
				dist[next] = d;
				pq.push({ -d, next });
				from[next] = now;
			}
		}
	}
}

void init()
{
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}
}

int main()
{
	int start, end;
	stack <int> ans;

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		path[s].push_back({ e, c });
	}
	cin >> start >> end;

	init();

	dijkstra(start, end);

	cout << dist[end] << "\n";

	int p = end;
	while (p != 0) {
		ans.push(p);
		p = from[p];
	}
	
	cout << ans.size() << "\n";
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
}