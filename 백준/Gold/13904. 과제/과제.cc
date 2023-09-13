#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent_node[1005];

int Find(int x)
{
	if (parent_node[x] == x)
		return x;
	
	return parent_node[x] = Find(parent_node[x]);
}

void Union(int x, int y)
{
	int x_parent = Find(x);
	int y_parent = Find(y);

	if (x_parent == y_parent)
		return;

	parent_node[y] = x_parent;
}

void init()
{
	for (int i = 0; i <= 1000; i++) {
		parent_node[i] = i;
	}
}

int main()
{
	int N, sum = 0;
	vector <pair<int, int>> assignments;	//<w, d-day>
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		assignments.push_back({ w, d });
	}

	init();
	sort(assignments.begin(), assignments.end(), greater<pair<int, int>>());

	for (auto e : assignments) {
		int d = e.second, w = e.first;

		int x = Find(d);

		if (x > 0) {
			sum += w;
			Union(x - 1, x);
		}
	}

	cout << sum;
}