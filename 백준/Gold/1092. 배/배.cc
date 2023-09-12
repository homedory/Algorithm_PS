#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	vector<int> crane, box;
	int ans = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		crane.push_back(x);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		box.push_back(x);
	}

	sort(crane.begin(), crane.end());
	sort(box.begin(), box.end());

	if (box.back() > crane.back()) {
		cout << -1;
		return 0;
	}
	
	while (!box.empty()) {
		
		for (int i = crane.size() - 1; i >= 0; i--) {
			int end = box.size() - 1;

			while (end > 0 && box[end] > crane[i]) {
				end--;
			}
			if (end >= 0 && box[end] <= crane[i]) {
				box.erase(box.begin() + end);
			}
		}
		ans++;
	}
	cout << ans;
}