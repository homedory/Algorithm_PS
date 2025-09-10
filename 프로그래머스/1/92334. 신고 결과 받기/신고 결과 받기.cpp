#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int reported[1005][1005];
int banned[1005];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_map<string,int> id_to_idx;
    
    int user_num = id_list.size();
    
    for (int i = 0; i < id_list.size(); i++) {
        id_to_idx[id_list[i]] = i;
    }
    
    for (auto r : report) {
        int idx = r.find(' ');
        int reporting_idx = id_to_idx[r.substr(0, idx)];
        int reported_idx = id_to_idx[r.substr(idx + 1)];
        
        reported[reporting_idx][reported_idx] = 1;
    }
    
    for (int i = 0; i < user_num; i++) {
        int report_cnt = 0;
        for (int j = 0; j < user_num; j++) {
            report_cnt += reported[j][i];
        }
        
        if (report_cnt >= k) {
            banned[i] = 1;
        }
    }
    
    for (int i = 0; i < user_num; i++) {
        int mail_cnt = 0;
        for (int j = 0; j < user_num; j++) {
            if (reported[i][j] == 1 && banned[j] == 1)
                mail_cnt++;
        }
        answer.push_back(mail_cnt);
    }
    
    return answer;
}