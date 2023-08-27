#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 2000000000
vector <pair<int, int>> Edges[500]; // pair<to, weight>
vector <int> from[500];
bool visited[500][500];

void init()
{	
	for (int i = 0; i < 500; i++) vector<int>().swap(from[i]); // clear vector
}

int dijkstra(int start, int end, int v)
{
	priority_queue<pair<int, int>> pq; // <weight, EndVerticed>
	int* dist = new int[v];
	for (int i = 0; i < v; i++) dist[i] = INF;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int now = pq.top().second;
		int nowdist = -pq.top().first;
		pq.pop();
		if (dist[now] < nowdist) continue;
		for (auto e : Edges[now]) {
			if (e.second == -1) continue;
			int d = nowdist + e.second;
			if (d == dist[e.first]) from[e.first].push_back(now);
			else if (d < dist[e.first]) {
				dist[e.first] = d;
				vector <int>().swap(from[e.first]); // clear vector
				from[e.first].push_back(now);
				pq.push({ -d, e.first });
			}
		}
	}
	return dist[end];
}

void removePath(int s)
{
	queue <int> q;
	memset(visited, false, sizeof(visited));
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto e : from[x]) {
			if (visited[x][e]) continue;
			visited[x][e] = true;
			for (int i = 0; i < Edges[e].size(); i++) {
				if (Edges[e][i].first == x) Edges[e][i].second = -1;
			}
			q.push(e);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	while (1)
	{
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 0; i < 500; i++) Edges[i].clear();
		int S, D, U, V, P, first, second;
		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			Edges[U].push_back({V, P});
		}
		init();
		first = dijkstra(S, D, N);
		
		removePath(D);
		init();
		second = dijkstra(S, D, N);
		if (second <= first || second == INF) cout << -1 << "\n";
		else cout << second << "\n";
	}
}