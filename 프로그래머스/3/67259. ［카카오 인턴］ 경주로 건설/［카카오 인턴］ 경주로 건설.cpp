#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Data {
    int total_dist;
    int row;
    int col;
    int dir;
};

struct CMP {
    bool operator() (const Data &a, const Data &b) const {
        return a.total_dist > b.total_dist;
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    const int INF = 1000000000;
    int dist[30][30][4];
    int r_len = board.size();
    int c_len = board[0].size();
    
    for (int r = 0; r < r_len; r++) {
        for (int c = 0; c < c_len; c++) {
            for (int i = 0; i < 4; i++) {
                dist[r][c][i] = INF;
            }
        }
    }
    
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    priority_queue<Data, vector<Data>, CMP> pq;
    
    pq.push({0,0,0,1});
    pq.push({0,0,0,3});
    dist[0][0][1] = 0;
    dist[0][0][3] = 0;
    
    while(!pq.empty()) {
        Data cur = pq.top();
        pq.pop();
        
        if (dist[cur.row][cur.col][cur.dir] < cur.total_dist)
            continue;
        
        for (int dir = 0; dir < 4; dir++) {
            int next_r = cur.row + dr[dir];
            int next_c = cur.col + dc[dir];
            
            if (next_r < 0 || next_r >= r_len || next_c < 0 || next_c >= c_len)
                continue;
            
            if (board[next_r][next_c])
                continue;
            
            int new_dist = cur.total_dist;
            if (dir == cur.dir)
                new_dist += 100;
            else
                new_dist += 600;
            
            if (dist[next_r][next_c][dir] > new_dist) {
                dist[next_r][next_c][dir] = new_dist;
                pq.push({new_dist, next_r, next_c, dir});
            }
        }
    }
    
    answer = min(dist[r_len-1][c_len-1][1], dist[r_len-1][c_len-1][3]);
    
    
    return answer;
}