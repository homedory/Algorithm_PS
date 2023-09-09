#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	string words[10];
	int alphabet_used[26];
	int value[26] = { 0 };
	vector<int> sorting_value;
	int ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	for (int i = 0; i < N; i++) {
		int l = words[i].length();
		int pow = 1;

		for (int j = 1; j <= l; j++) {
			alphabet_used[words[i][l - j] - 'A'] = 1;
			value[words[i][l - j] - 'A'] += pow;
			pow *= 10;
		}
	}

	//put counted values to sorting_value
	for (int i = 0; i < 26; i++) {
		if (alphabet_used[i]) {
			sorting_value.push_back(value[i]);
		}
	}

	sort(sorting_value.begin(), sorting_value.end());

	int number = 9;
	for (int i = sorting_value.size() - 1; i >= 0; i--) {
		ans += number * sorting_value[i];
		number--;
	}

	cout << ans;
}