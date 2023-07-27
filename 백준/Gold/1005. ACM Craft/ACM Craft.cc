#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T, N, K;
	cin >> T;
	while (T--) {
		vector <int> v[1005];
		int d[1005], dp[1005], input_arrow[1005];
		int X, Y, W;
		priority_queue < pair<int, int>> pq;

		cin >> N >> K;

		for (int i = 0; i <= N; i++) {
			input_arrow[i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			cin >> d[i];
		}

		for (int i = 1; i <= K; i++) {
			cin >> X >> Y;
			input_arrow[Y] += 1;
			v[X].push_back(Y);
		}
		cin >> W;

		for (int i = 1; i <= N; i++) {
			if (input_arrow[i] == 0) {
				pq.push(make_pair(-d[i], i));
			}
		}

		int ans = d[W]; //if building W can be contructed at first, then answer is d[W]

		while (!pq.empty() && input_arrow[W]) {
			int t = -pq.top().first, building = pq.top().second;
			pq.pop();
			for (int i = 0; i < v[building].size(); i++) {
				int next = v[building][i];
				if (--input_arrow[next] == 0) {
					pq.push(make_pair(-(t + d[next]), next));
					if (next == W) {
						ans = t + d[next];
					}
				}
			}
		}
		cout << ans << "\n";
	}
}