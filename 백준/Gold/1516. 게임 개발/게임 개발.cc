#include <iostream>
#include <vector>
using namespace std;

#define INF 2000000000

int main()
{
	int N;
	int T[505], dp[505];
	vector <int> order[505];
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		while (1) {
			int a;
			cin >> a;
			if (a == -1) break;
			order[i].push_back(a);
		}
	}

	//initialize
	for (int i = 1; i <= N; i++) {
		dp[i] = INF;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			if (order[j].size() == 0) {
				dp[j] = T[j];
			}
			else {
				int max_time = 0;
				for (int k = 0; k < order[j].size(); k++) {
					if (dp[order[j][k]] == INF) {
						max_time = 0;
						break;
					}
					else {
						max_time = max(max_time, dp[order[j][k]]);
					}
				}
				if (max_time != 0) {
					dp[j] = min(dp[j], max_time + T[j]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << "\n";
	}
}