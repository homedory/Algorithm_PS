#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> orders;
vector<string> candidate;

int max_cnt = 2;

void combination(int idx, int cnt, int r, string selected) {
    if (idx > 26)
        return;
    
    if (cnt == r) {
        int contain_cnt  = 0;
        for (auto order : orders) {
            bool isPossible = true;
            for (auto ch : selected) {
                if (order.find(ch) == string::npos) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible)
                contain_cnt++;
        }
        
        if (contain_cnt > max_cnt) {
            candidate.clear();
            candidate.push_back(selected);
            max_cnt = contain_cnt;
        }
        else if (contain_cnt == max_cnt) {
            candidate.push_back(selected);
        }
        return;
    }
    
    char c = ('A' + idx);
    combination(idx + 1, cnt + 1, r, selected + c);
    combination(idx + 1, cnt, r, selected);
}

vector<string> solution(vector<string> ord, vector<int> course) {
    vector<string> answer;
    orders = ord;
    
    for (auto c : course) {
        max_cnt = 2;
        candidate.clear();
        combination(0, 0, c, "");
        
        for (auto cand : candidate) {
            answer.push_back(cand);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}