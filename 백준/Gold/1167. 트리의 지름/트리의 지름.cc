#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int>> edge[100005];
int max_num = 0;

int dfs(int parent, int node)
{
	priority_queue <int> pq;
	int first_largest, second_largest;

	for (auto e : edge[node]) {
		if (e.first == parent)
			continue;

		pq.push(dfs(node, e.first) + e.second);
	}

	if (pq.size() >= 2) {
		first_largest = pq.top();
		pq.pop();
		second_largest = pq.top();
		pq.pop();
		max_num = max(max_num, first_largest + second_largest);
		return first_largest;
	}
	else if (pq.size() > 0) {
		max_num = max(max_num, pq.top());
		return pq.top();
	}
	else {
		return 0;
	}
}

int main()
{
	int V;
	cin >> V;
	for (int i = 0; i < V; i++) {
		int a, b, c;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) {
				break;
			}
			cin >> c;
			edge[a].push_back({ b,c });
		}	
	}

	dfs(0, 1);

	cout << max_num;
}