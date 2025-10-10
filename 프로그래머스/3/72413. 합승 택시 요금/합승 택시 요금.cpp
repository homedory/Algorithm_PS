#include <string>
#include <vector>

using namespace std;

#define INF 100000000
int dp[205][205];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
            if (i == j) {
                dp[i][j] = 0;
            }
        }
    }
    
    for (auto f : fares) {
        dp[f[0]][f[1]] = f[2];
        dp[f[1]][f[0]] = f[2];
    }
    
    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                if (dp[start][end] > dp[start][mid] + dp[mid][end]) {
                    dp[start][end] = dp[start][mid] + dp[mid][end];
                }
            }
        }
    }
    
    int min_fare = dp[s][a] + dp[s][b];
    
    for (int node = 1; node <= n; node++) {
        if (min_fare > dp[s][node] + dp[node][a] + dp[node][b]) {
            min_fare = dp[s][node] + dp[node][a] + dp[node][b];
        }
    }
    
    return min_fare;
}