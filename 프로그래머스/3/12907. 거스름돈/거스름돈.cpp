#include <string>
#include <vector>

using namespace std;

int dp[100005];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    dp[0] = 1;
    for (int i = 0; i < money.size(); i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= money[i]) {
                dp[j] += dp[j - money[i]];
                dp[j] = dp[j] % 1000000007;
            }
        }    
    }
    
    
    return dp[n];
}