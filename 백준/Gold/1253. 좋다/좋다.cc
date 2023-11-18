#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check[2005];

int main()
{
	vector <int> A;
	int N, sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int x = A[i] + A[j];
			int l = lower_bound(A.begin(), A.end(), x) - A.begin();
			int u = upper_bound(A.begin(), A.end(), x) - A.begin();
			if (l >= N || l == i || l == j)
				continue;

			if (x == A[l] && check[l] == 0) {
				check[l] = 1;
				sum += u - l;
			}
		}
	}

	cout << sum;
}