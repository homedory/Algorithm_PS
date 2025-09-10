#include <string>
#include <vector>

using namespace std;

#define MOD 10007
int dp[100005][2];

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    for (int i = 1; i < n + 1; i++) {
        if (tops[i-1]) {
            dp[i][0] += dp[i-1][0] + dp[i-1][1];
        }
        dp[i][0] += 2 * dp[i-1][0] + dp[i-1][1];
        dp[i][0] %= MOD;
        
        dp[i][1] += dp[i-1][0] + dp[i-1][1];
        dp[i][1] %= MOD;
    }
    
    answer = (dp[n][0] + dp[n][1]) % MOD;
    
    return answer;
}