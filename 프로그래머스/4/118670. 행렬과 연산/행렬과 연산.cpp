#include <string>
#include <vector>
#include <deque>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int height = rc.size();
    int width = rc[0].size();
    
    deque<int> left_col, right_col;
    deque<deque<int>*> rows;
    deque<int> dq[height];
    
    answer.resize(height);
    for (int i = 0; i < height; i++) {
        left_col.push_back(rc[i][0]);
        right_col.push_back(rc[i][width-1]);
        for (int j = 1; j < width - 1; j++) {
            dq[i].push_back(rc[i][j]);
        }
        rows.push_back(&dq[i]);
        answer[i].resize(width);
    }
    
    for (auto op : operations) {
        if (op == "ShiftRow") {
            left_col.push_front(left_col.back());
            left_col.pop_back();
            right_col.push_front(right_col.back());
            right_col.pop_back();
            rows.push_front(rows.back());
            rows.pop_back();
        }
        else {
            rows.front()->push_front(left_col.front());
            left_col.pop_front();
            right_col.push_front(rows.front()->back());
            rows.front()->pop_back();
            rows.back()->push_back(right_col.back());
            right_col.pop_back();
            left_col.push_back(rows.back()->front());
            rows.back()->pop_front();
        }
    }
    
    for (int r = 0; r < height; r++) {
        answer[r][0] = left_col[r];
        answer[r][width-1] = right_col[r];
        for (int c = 1; c < width - 1; c++) {
            answer[r][c] = (*rows[r])[c-1];
        }
    }
    
    return answer;
}