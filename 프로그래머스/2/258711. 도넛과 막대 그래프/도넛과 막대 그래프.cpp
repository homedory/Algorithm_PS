#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int visited[1000005];
int in_order[1000005];
int out_order[1000005];
vector<int> connected_nodes[1000005];


int find_type(int start) {
    in_order[start]--;
    
    queue<int> q;
    visited[start] = 1;
    q.push(start);
        
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (out_order[cur] > 1) {
            return 3;
        }
        else if (out_order[cur] != in_order[cur]) {
            return 2;
        }
        
        for (auto n : connected_nodes[cur]) {
            if (visited[n]) 
                continue;
            
            q.push(n);
            visited[n] = 1;
        }
    }
    
    if (in_order[start] == 0 && out_order[start] == 0)
        return 2;
    
    return 1;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    unordered_set<int> nodes;
    answer.resize(4, 0);
    
    for (auto e : edges) {
        out_order[e[0]]++;
        in_order[e[1]]++;
        connected_nodes[e[0]].push_back(e[1]);
        nodes.insert(e[0]);
        nodes.insert(e[1]);
    }
    
    int start = 0;
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        if (out_order[*it] >= 2 && in_order[*it] == 0) {
            start = *it;
            break;
        }
    }
    
    answer[0] = start;
    for (auto n : connected_nodes[start]) {
        int type = find_type(n);
        answer[type]++;
    }
    
    return answer;
}