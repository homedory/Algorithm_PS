#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connected[20005];
vector <pair<int, int>> edge[200005]; //<to, distance>
priority_queue <pair<int, int>> pq; //<distance, to>

void init()
{
	for (int i = 0; i < 20005; i++) {
		connected[i] = 0;
		edge[i].clear();
	}
}

int main()
{
	while (1) {
		int m, n, total_cost = 0, sum = 0;
		int x, y, z;

		//initialize
		init();

		//input
		cin >> m >> n;
		if (m == 0 && n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			edge[x].push_back({ y, z });
			edge[y].push_back({ x, z });
			total_cost += z;
		}


		//solution
		pq.push({ 0,0 });

		while (!pq.empty()) {
			int d = -pq.top().first;
			int v = pq.top().second;
			pq.pop();

			if (connected[v]) {
				continue;
			}

			connected[v] = 1;
			sum += d;

			for (auto e : edge[v]) {
				if (connected[e.first] == 0) {
					pq.push({ -e.second, e.first });
				}
			}
		}

		cout << total_cost - sum << "\n";
	}
	
}