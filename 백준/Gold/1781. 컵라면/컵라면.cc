#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[200005];

int find(int a) {
	if (parent[a] == a)
		return a;

	return parent[a] = find(parent[a]);
}

void join(int a, int b) {
	int a_parent = find(a);
	int b_parent = find(b);

	parent[a_parent] = b_parent;
}

int main()
{
	int N, sum = 0;
	vector <pair<int, int>> problems; //<cup_ramen, deadline>
	
	//input
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, d;
		cin >> d >> c;
		problems.push_back({ c, d });
	}

	//initailize
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	//solution
	sort(problems.begin(), problems.end(), greater<pair<int, int>>());
	
	for (auto e : problems) {
		int p = find(e.second);
		if (p != 0) {
			sum += e.first;
			join(p, p - 1);
		}
	}
	
	cout << sum;
}