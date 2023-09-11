#include <iostream>
#include <vector>
using namespace std;

int parent[100005];
int G, P, ans = 0;

void init()
{
	for (int i = 0; i <= G; i++) {
		parent[i] = i;
	}
}

int Find(int x)
{
	if (parent[x] == x) return x;

	return parent[x] = Find(parent[x]);
}

void Union (int a, int b)
{
	parent[a] = Find(b);
}

int main()
{
	vector <int> plane;

	cin >> G >> P;

	init();

	for (int i = 0; i < P; i++) {
		int g;
		cin >> g;
		plane.push_back(g);
	}

	for (int i = 0; i < plane.size(); i++) {
		int g = plane[i];
		int x = Find(g);
		
		if (x > 0) {
			ans++;
			Union(x, x - 1);
		}
		else {
			break;
		}	
	}

	cout << ans;
}