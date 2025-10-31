#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits> 
using namespace std;

void preOrder(int left, int right, int level, vector<vector<pair<int,int>>> &node, vector<int> &order) {
    if (level == node.size()) {
        return;
    }
    
    int idx = upper_bound(node[level].begin(), node[level].end(), make_pair(left, INT_MAX)) - node[level].begin();
    if (idx == node[level].size() || node[level][idx].first >= right)
        return;
    
    auto [cur_x, node_num] = node[level][idx];
    order.push_back(node_num);
    
    // left
    preOrder(left, cur_x, level+1, node, order);
    // right
    preOrder(cur_x, right, level+1, node, order);
}

void postOrder(int left, int right, int level, vector<vector<pair<int,int>>> &node, vector<int> &order) {
    if (level == node.size()) {
        return;
    }
    
    int idx = upper_bound(node[level].begin(), node[level].end(), make_pair(left, INT_MAX)) - node[level].begin();
    
    if (idx == node[level].size() || node[level][idx].first >= right)
        return;
    
    auto [cur_x, node_num] = node[level][idx];
    
    // left
    postOrder(left, cur_x, level+1, node, order);
    // right
    postOrder(cur_x, right, level+1, node, order);
    
    order.push_back(node_num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<int> y_val;
    for (auto node : nodeinfo) {
        int x = node[0];
        int y = node[1];
        y_val.push_back(y);
    }
    
    sort(y_val.begin(), y_val.end());
    y_val.erase(unique(y_val.begin(), y_val.end()), y_val.end());
    reverse(y_val.begin(), y_val.end());
    
    unordered_map<int,int> level;
    int lev = 0;
    for (auto y : y_val) {
        level[y] = lev++;
    }
    
    vector<vector<pair<int,int>>> node(lev);
    
    int num = 1;
    for (auto info : nodeinfo) {
        int x = info[0];
        int y = info[1];
        int l = level[y];
        
        node[l].push_back(make_pair(x,num++));
    }
    for (int l = 0; l < lev; l++) {
        sort(node[l].begin(), node[l].end());
    }
    
    vector<vector<int>> answer(2, vector<int>());


    int minx = INT_MAX, maxx = INT_MIN;
    for (auto &info : nodeinfo) {
        minx = min(minx, info[0]);
        maxx = max(maxx, info[0]);
    }
    
    preOrder(minx - 1, maxx + 1, 0, node, answer[0]);
    postOrder(minx - 1, maxx + 1, 0, node, answer[1]);
    
    return answer;
}

