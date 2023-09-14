#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, ans = 0;
	vector<int> books_posiive, books_negative;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			books_posiive.push_back(x);
		}
		else {
			books_negative.push_back(x);
		}
	}

	sort(books_posiive.begin(), books_posiive.end());
	sort(books_negative.begin(), books_negative.end());

	for (int i = books_posiive.size() - 1; i >= 0; i -= M) {
		ans += 2 * books_posiive[i];
	}

	for (int i = 0; i < books_negative.size(); i += M) {
		ans += (-2) * books_negative[i];
	}

	int l, r;

	if (books_negative.size() == 0) {
		l = 0;
	}
	else {
		l = -books_negative.front();
	}
	if (books_posiive.size() == 0) {
		r = 0;
	}
	else {
		r = books_posiive.back();
	}

	int d = max(l, r);

	ans -= d;

	cout << ans;
}