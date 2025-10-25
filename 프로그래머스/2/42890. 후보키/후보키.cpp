#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void findCandidateKey(int selected, int num, int cnt, vector<int> &not_unique, vector<vector<string>> &relation) {
    int column_cnt = relation[0].size();
    
    if (num == cnt) {
        if (not_unique[selected])
            return;
        
        vector<string> vec;
        for (auto row : relation) {
            string str = "";
            for (int i = 0; i < column_cnt; i++) {
                if (selected & (1<<i)) {
                    str += row[i];
                }
            }
            vec.push_back(str);
        }
        int prev = vec.size();
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        
        if (prev != vec.size()) {
            not_unique[selected] = 1;
            return;
        }
        
        /*
        if (unique(vec.begin(), vec.end()) != vec.end()) {
            not_unique[selected] = 1;
            return;
        }
        */
        
        for (int i = 0; i <= (1<<column_cnt) - 1; i++) {
            if (i == selected)
                continue;
            
            if ((selected & i) == selected) {
                not_unique[i] = 1;
            }
        }
        return;
    }
    
    for (int i = 0; i < column_cnt; i++) {
        if (selected & (1<<i))
            continue;
        
        findCandidateKey(selected | (1<<i), num, cnt+1, not_unique, relation);
    }
}

int solution(vector<vector<string>> relation) {
    int column_cnt = relation[0].size();
    int row_cnt = relation.size();
    vector<int> not_unique((1<<column_cnt), 0);
    
    for (int num = 1; num <= column_cnt; num++) {
        findCandidateKey(0, num, 0, not_unique, relation);
    }
    
    int answer = 0;
    for (int i = 1; i <= (1<<column_cnt)-1; i++) {
        if (not_unique[i])
            continue;
        answer++;
    }
    
    return answer;
}