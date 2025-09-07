#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int graph[55][55];
int cnt[55];
int gift_points[55];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    unordered_map<string, int> name_to_index;
    
    int friends_cnt = 0;
    for (auto name : friends) {
        name_to_index[name] = friends_cnt;
        friends_cnt++;
    }
    
    for (auto t : gifts) {
        int pos = t.find(' ');
        string giver = t.substr(0, pos);
        string receiver = t.substr(pos + 1);
        
        graph[name_to_index[giver]][name_to_index[receiver]] += 1;
        gift_points[name_to_index[giver]] += 1;
        gift_points[name_to_index[receiver]] -= 1;
    }
    
    for (int i = 0; i < friends_cnt; i++) {
        for (int j = i; j < friends_cnt; j++) {
            if (graph[i][j] == graph[j][i]) {
                if (gift_points[i] == gift_points[j])
                    continue;
                
                if (gift_points[i] > gift_points[j]) {
                    cnt[i]++;
                }
                else {
                    cnt[j]++;
                }
            }
            else if (graph[i][j] > graph[j][i]) {
                cnt[i]++;
            }
            else {
                cnt[j]++;
            }
        }
    }
    
    for (int i = 0; i < friends_cnt; i++) {
        answer = max(answer, cnt[i]);
    }
    
    return answer;
}