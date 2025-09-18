#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int row_length, col_length;
vector<vector<int>> board;

bool inRange(int r, int c) {
    return r >= 0 && r < row_length && c >= 0 && c < col_length;
}


int backtracking(int depth, int ar, int ac, int br, int bc) {
    int choice = 0;
    
    bool moved = false;
    // A turn
    if (depth % 2 == 0) {
        
        if (board[ar][ac] == 0) {
            return depth;
        }
        
        choice = 0;
        
        for (int i = 0; i < 4; i++) {
            int nr = ar + dr[i];
            int nc = ac + dc[i];
            
            if (!inRange(nr, nc) || board[nr][nc] == 0)
                continue;
            
            moved = true;
            
            board[ar][ac] = 0;
            int result = backtracking(depth + 1, nr, nc, br, bc);
            board[ar][ac] = 1;
            
            // A can win
            if (result % 2 == 1) {
                if (choice % 2 == 1)
                    choice = min(result, choice);
                else
                    choice = result;
            }
            // A cannot win
            else {
                // To survive longer
                if (choice % 2 == 0)
                    choice = max(result, choice);
            }
        }
    }
    else {
        if (board[br][bc] == 0) {
            return depth;
        }
        
        choice = 1;
        
        for (int i = 0; i < 4; i++) {
            int nr = br + dr[i];
            int nc = bc + dc[i];
            
            if (!inRange(nr, nc) || board[nr][nc] == 0)
                continue;
            
            moved = true;
            
            board[br][bc] = 0;
            int result = backtracking(depth + 1, ar, ac, nr, nc);
            board[br][bc] = 1;
            
            // can win
            if (result % 2 == 0) {
                if (choice % 2 == 0)
                    choice = min(result, choice);
                else
                    choice = result;
            }
            // cannot win
            else {
                // To survive loner
                if (choice % 2 == 1)
                    choice = max(result, choice);
            }
        }
    }
    
    if (!moved) {
        return depth;
    }
    
    return choice;
}

int solution(vector<vector<int>> board_, vector<int> aloc, vector<int> bloc) {
    board = board_;
    row_length = board_.size();
    col_length = board_[0].size();
   
    int answer = backtracking(0, aloc[0], aloc[1], bloc[0], bloc[1]);
    
    return answer;
}