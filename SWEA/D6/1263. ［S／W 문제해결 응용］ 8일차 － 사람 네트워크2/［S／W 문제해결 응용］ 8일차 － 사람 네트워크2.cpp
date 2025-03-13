#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 1001
#define INF 1000000000
int dist[MAX_N][MAX_N];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);

		// Initialize
		for (int i = 1; i <= N; ++i) {
			fill(dist[i], dist[i] + N + 1, INF);
			dist[i][i] = 0;
		}
		
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				int adj;
				scanf("%d", &adj);
				if (adj)
					dist[i][j] = 1;
			}
		}

		

		for (int m = 1; m <= N; ++m) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][m] + dist[m][j]);
				}
			}
		}

		int min_cc = INF;
		for (int n = 1; n <= N; ++n) {
			int cc = 0;
			for (int i = 1; i <= N; ++i) {
				cc += dist[n][i];
			}
			min_cc = min(min_cc, cc);
		}

		printf("#%d %d\n", test_case, min_cc);
	}

	return 0;
}