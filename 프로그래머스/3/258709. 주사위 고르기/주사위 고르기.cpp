#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dice_num;
int selected[10];
vector<int> answer;
int max_total_win_cnt = 0;
int total_win_cnt;
vector<vector<int>> dice_list;

vector<int> sum_list;

void init() {
    sum_list.clear();
    total_win_cnt = 0;
}

void build_sum_list(int idx, int cnt, int sum) {
    if (cnt == dice_num / 2) {
        sum_list.push_back(sum);
        return;
    }
    
    if (idx == dice_num)
        return;
    
    if (selected[idx]) {
        build_sum_list(idx + 1, cnt, sum);
    }
    else {
        for (int i = 0; i < 6; i++) {
            build_sum_list(idx + 1, cnt + 1, sum + dice_list[idx][i]);
        }
    }
}

int calc_win_cnt(int sum) {
    return lower_bound(sum_list.begin(), sum_list.end(), sum) - sum_list.begin();
}


void choose_dice_num(int idx, int cnt, int sum) {
    if (cnt == dice_num / 2) {
        total_win_cnt += calc_win_cnt(sum);
        return;
    }
    
    if (idx == dice_num)
        return;
    
    if (selected[idx]) {
        for (int i = 0; i < 6; i++) {
            choose_dice_num(idx + 1, cnt + 1, sum + dice_list[idx][i]);
        }
    }
    else {
        choose_dice_num(idx + 1, cnt, sum);
    }
}



void combination(int idx, int cnt) {
    if (cnt == dice_num / 2) {
        init();
        
        build_sum_list(0, 0, 0);
        
        sort(sum_list.begin(), sum_list.end());
        
        choose_dice_num(0, 0, 0);
        
        if (total_win_cnt > max_total_win_cnt) {
            answer.clear();
            
            for (int i = 0; i < dice_num; i++) {
                if (selected[i])
                    answer.push_back(i+1);
            }
            
            max_total_win_cnt = total_win_cnt;
        }
        
        return;
    }
    
    if (idx == dice_num)
        return;
    
    combination(idx + 1, cnt);
    
    selected[idx] = 1;
    combination(idx + 1, cnt + 1);
    selected[idx] = 0;
}


vector<int> solution(vector<vector<int>> dice) {
    dice_list = dice;
    
    dice_num = dice.size();
    
    combination(0, 0);
    
    return answer;
}