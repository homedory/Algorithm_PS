#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define NEG_INF -100000000

int dp[15][15];
int select_cnt[15][15];


vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = NEG_INF;
        }
    }
    
    // Initialize
    for (int i = 0; i <= n; i++) {
        if (info[0] < i) {
            dp[0][i] = 10;
        }
        else if (info[0] > 0) {
            dp[0][i] = -10;
        }
        else {
            dp[0][i] = 0;
        }
        select_cnt[0][i] = i;
    }
    
    for (int i = 1; i < 11; i++) {
        int point = 10 - i;
        
        for (int select = 0; select <= n; select++) {
            for (int j = 0; j + select <= n; j++) {
                
                int value = dp[i-1][j];
                
                if (info[i] == 0) {
                    if (select > 0) {
                        value += point;
                    }
                }
                else {
                    if (info[i] < select) {
                        value += point;
                    }
                    else {
                        value -= point;
                    }
                }
                
                if (dp[i][j+select] <= value) {
                    select_cnt[i][j+select] = select;
                    dp[i][j+select] = value;
                }
            }
        }
    }
    
    // check if RYAN can win
    if (dp[10][n] <= 0) {
        answer.push_back(-1);
        return answer;
    }
    
    int remain = n;
    
    for (int i = 10; i >= 0; i--) {
        answer.push_back(select_cnt[i][remain]);
        remain -= select_cnt[i][remain];
    }
    
    reverse(answer.begin(), answer.end());
    
    
    return answer;
}