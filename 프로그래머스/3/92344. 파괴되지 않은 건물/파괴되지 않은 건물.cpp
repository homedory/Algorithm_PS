#include <string>
#include <vector>

using namespace std;

long long sum[1005][1005];
long long result[1005][1005];

void performSkill(int type, int r1, int c1, int r2, int c2, int degree) {
    if (type == 1) {
        degree *= (-1);
    }
    
    sum[r2][c2] += degree;
    
    if (r1 > 0) {
        sum[r1-1][c2] -= degree;
    }
    if (c1 > 0) {
        sum[r2][c1-1] -= degree;
    }
    
    if (r1 > 0 && c1 > 0) {
        sum[r1-1][c1-1] += degree;
    }
}

void getResult(vector<vector<int>> &board) {
    int row_size = board.size();
    int col_size = board[0].size();
    
    for (int r = row_size - 1; r >= 0; r--) {
        for (int c = col_size - 1; c >= 0; c--) {
            if (r < row_size - 1) {
                sum[r][c] += sum[r+1][c];
            }
            if (c < col_size - 1) {
                sum[r][c] += sum[r][c+1];   
            }
            if (r < row_size - 1 && c < col_size - 1) {
                sum[r][c] -= sum[r+1][c+1];
            }
            result[r][c] += sum[r][c];
            result[r][c] += board[r][c];
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for (auto s : skill) {
        performSkill(s[0], s[1], s[2], s[3], s[4], s[5]);
    }
    
    getResult(board);
    
    // count building 
    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board[0].size(); c++) {
            if (result[r][c] > 0)
                answer++;
        }
    }
    
    return answer;
}