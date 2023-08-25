#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2000000000

vector <pair<int, int>> path[2005];			//<to, distance>
int dist[2005];


void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;		//<distance, to>

	//initailize
	for (int i = 0; i < 2005; i++) {
		dist[i] = INF;
	}
	

	pq.push({ 0, start });
	
	while (!pq.empty()) {
		int now_dist = -pq.top().first, now = pq.top().second;
		pq.pop();

		if (dist[now] != INF) 
			continue;

		dist[now] = now_dist;

		for (int i = 0; i < path[now].size(); i++) {
			int to = path[now][i].first, d = path[now][i].second;

			if (dist[to] == INF) {
				pq.push({ -(now_dist + d), to });
			}
		}
	}
}


void init()
{
	for (int i = 0; i < 2005; i++) {
		path[i].clear();
	}
}


int main()
{
	int T;
	cin >> T;

	while (T--) {
		vector <int> ans;
		vector <int> dest_candidate;
		int n, m, t, s, g, h;
		priority_queue <pair<int, pair<int, bool>>> pq;		//<distance, <to, passed>>
		int g_h_distance;
		int dist_from_s[2005], dist_from_g[2005], dist_from_h[2005];

		//initialize
		init();

		//input
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			path[a].push_back({ b, d });
			path[b].push_back({ a, d });
			//find distance (g,h)
			if ((a == g && b == h) || (a == h && b == g)) {
				g_h_distance = d;
			}
		}
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			dest_candidate.push_back(x);
		}


		//sort destination_candidate with increasing order
		sort(dest_candidate.begin(), dest_candidate.end());

		//calculate distance from s
		dijkstra(s);
		for (int i = 1; i <= n; i++) {
			dist_from_s[i] = dist[i];
		}

		//calculate distance from g
		dijkstra(g);
		for (int i = 1; i <= n; i++) {
			dist_from_g[i] = dist[i];
		}
		
		//calculate distance from h
		dijkstra(h);
		for (int i = 1; i <= n; i++) {
			dist_from_h[i] = dist[i];
		}
		

		int s_to_g = dist_from_s[g], s_to_h = dist_from_s[h];

		for (int i = 0; i < dest_candidate.size(); i++) {
			int x = dest_candidate[i];

			//check  s -> g-> h -> destinaiton == s -> destination  or  s -> h -> g -> destination
			if ((s_to_g + g_h_distance + dist_from_h[x] == dist_from_s[x]) || (s_to_h + g_h_distance + dist_from_g[x] == dist_from_s[x]))
				cout << x << " ";
		}
		cout << "\n";
	}
}