#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[300005], diff[300005];

int main()
{
	int N, K, sum = 0;
	vector <int> diff;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i > 0) {
			sum += arr[i] - arr[i - 1];
			diff.push_back(arr[i] - arr[i - 1]);
		}
	}
	
	sort(diff.begin(), diff.end(), greater<int>());

	for (int i = 0; i < K - 1; i++) {
		sum -= diff[i];
	}

	cout << sum;
}