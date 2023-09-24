#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, visit[1005];
vector <pair<int, int>>  edge[1005];

int main()
{
	int cnt = 1, ans = 0;
	priority_queue <pair<int, int>> pq;

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	
	visit[1] = 1;
	for (auto e : edge[1]) {
		pq.push({ -e.second, e.first });
	}

	while (cnt < N) {
		int c = -pq.top().first, now = pq.top().second;
		pq.pop();

		if (visit[now])
			continue;

		visit[now] = 1;
		ans += c;
		cnt++;

		for (auto e : edge[now]) {
			pq.push({ -e.second, e.first });
		}
	}

	cout << ans;
}