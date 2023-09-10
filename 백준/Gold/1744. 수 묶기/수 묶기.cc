#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, sum = 0;
	vector <int> negative_zero, positive;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			positive.push_back(x);
		}
		else {
			negative_zero.push_back(x);
		}
	}
	
	//sort positive descending, negative_zero ascending
	sort(positive.begin(), positive.end(), greater<int>());
	sort(negative_zero.begin(), negative_zero.end());
	
	for (int i = 0; i < positive.size(); i++) {
		if (i < positive.size() - 1) {
			if (positive[i + 1] == 1) {
				sum += (positive[i] + positive[i + 1]);
			}
			else {
				sum += (positive[i] * positive[i + 1]);
			}
			i++;
		}
		else {
			sum += positive[i];
		}
	}

	for (int i = 0; i < negative_zero.size(); i++) {
		if (i < negative_zero.size() - 1) {
			sum += (negative_zero[i] * negative_zero[i + 1]);
			i++;
		}
		else {
			sum += negative_zero[i];
		}
	}

	cout << sum;
}