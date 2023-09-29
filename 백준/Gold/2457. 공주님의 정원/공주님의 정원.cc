#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int month[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int main()
{
	vector <pair<int, int>> flowers;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int start_month, start_day, end_month, end_day;

		cin >> start_month >> start_day >> end_month >> end_day;
		flowers.push_back({ month[start_month] + start_day, month[end_month] + end_day });
	}

	sort(flowers.begin(), flowers.end());

	int ans = 0, idx = 0;
	int end = 60;
	while (end < 335) {
		
		if (idx == flowers.size() || end == 0) {
			ans = 0;
			break;
		}

		int max_end = 0;

		while (idx < flowers.size() && flowers[idx].first <= end) {
			max_end = max(max_end, flowers[idx].second);
			idx++;
		}

		end = max_end;
		ans++;
	}

	cout << ans;
}