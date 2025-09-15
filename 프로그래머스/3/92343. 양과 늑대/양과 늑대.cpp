#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> child[20];
int parent[20];
int type[20];
int current_sheep;
int current_fox;
int max_depth;

void traverse(vector<pair<int,int>> &reachable, long long visited) {
    queue<pair<int,int>> q; 
    q.push(make_pair(0,0));
    
    while(!q.empty()) {
        int cur = q.front().first;
        int fox_cnt = q.front().second;
        q.pop();
        
        if (current_sheep > current_fox + fox_cnt  && type[cur] == 0 && ((visited & (1 << cur)) == 0)) {
            reachable.push_back({cur, fox_cnt});
            continue;
        }
        
        if ((visited & (1 << cur)) == 0 && type[cur] == 1) {
            fox_cnt++;
        }
        
        for (auto c : child[cur]) {
            q.push(make_pair(c, fox_cnt));
        }
    }
}

long long visit_node(int node, long long visited) {
    while(node != 0) {
        visited |= 1 << node;
        node = parent[node];
    }
    
    return visited;
}

void backtracking(int depth, long long visited) {
    max_depth = max(max_depth, depth);
    vector<pair<int,int>> reachable; // <node, fox_cnt>
    traverse(reachable, visited);
    
    for (auto next_node : reachable) {
        int node = next_node.first;
        int fox_cnt = next_node.second;
        
        current_sheep += 1;
        current_fox += fox_cnt;
        
        backtracking(depth + 1, visit_node(node, visited));
        
        current_sheep -= 1;
        current_fox -= fox_cnt;
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    current_sheep = 1;
    long long visited = 1;
    for (int i = 0; i < info.size(); i++) {
        type[i] = info[i];
    }
    
    for (auto e : edges) {
        parent[e[1]] = e[0];
        child[e[0]].push_back(e[1]);
    }
    
    backtracking(1, visited);
    
    return max_depth;
}