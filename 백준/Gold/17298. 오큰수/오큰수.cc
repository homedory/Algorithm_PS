#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int N;
	vector <int> arr, ans;
	stack <pair<int, int>> s;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
		ans.push_back(-1);
	}

	s.push({ arr[0], 0 });
	for (int i = 1; i < N; i++) {
		while (!s.empty() && s.top().first < arr[i]) {
			ans[s.top().second] = arr[i];
			s.pop();
		}
		s.push({ arr[i], i });
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

}