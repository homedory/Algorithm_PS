#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10005];

int Find(int x)
{
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int x = Find(a);
	int y = Find(b);

	parent[x] = y;
}

void init()
{
	for (int i = 0; i < 10005; i++) {
		parent[i] = i;
	}
}

int main()
{
	int n, ans = 0;
	vector <pair<int, int>> lectures;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		lectures.push_back({ p,d });
	}

	init();

	sort(lectures.begin(), lectures.end(), greater <pair<int,int>>());

	for (auto e : lectures) {
		int p = e.first, d = e.second;
		int loc = Find(d);

		if (loc > 0) {
			ans += p;
			Union(loc, loc - 1);
		}
	}

	cout << ans;
}