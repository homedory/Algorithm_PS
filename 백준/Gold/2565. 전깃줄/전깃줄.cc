#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int arr[505], dp[505];
	vector <int> v;
	int max_num = 0;

	//initialize
	for (int i = 0; i < 505; i++) {
		arr[i] = 0;
		dp[i] = 1;
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	for (int i = 1; i <= 500; i++) {
		if (arr[i] > 0) {
			v.push_back(arr[i]);
		}
	}

	
	for (int i = 0; i < v.size(); i++) {
		int x = v[i];
		for (int j = 0; j < i; j++) {
			if (x > v[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		max_num = max(dp[i], max_num);
	}

	cout << N - max_num;
}
