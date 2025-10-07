#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    vector<int> condition;
    vector<int> next_order;
    vector<int> visited;
    vector<vector<int>> edge;
    
    condition.resize(n+1, 0);
    next_order.resize(n+1);
    visited.resize(n+1, 0);
    edge.resize(n+1);
    
    for (auto p : path) {
        edge[p[0]].push_back(p[1]);
        edge[p[1]].push_back(p[0]);
    }
    
    for (auto o : order) {
        condition[o[1]] = 1;
        next_order[o[0]] = o[1];
    }
    
    queue<int> q;
    
    if (condition[0] == 0)
        q.push(0);
    
    unordered_set<int> waiting;
    
    int visit_count  = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        visit_count++;
        
        visited[cur] = 1;
        
        if (next_order[cur] != 0) {
            condition[next_order[cur]] = 0;
            if (waiting.find(next_order[cur]) != waiting.end()) {
                q.push(next_order[cur]);
            }
        }
            
        for (auto e : edge[cur]) {
            if (visited[e])
                continue;
            
            if (condition[e]) {
                waiting.insert(e);
            }
            else {
                q.push(e);
            }
        }
    }
    
    if (visit_count != n)
        answer = false;
    
    return answer;
}