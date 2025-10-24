#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool permutation(vector<int> &candidate, vector<int> &weak, int weak_idx, int selected) {
    if (weak_idx >= weak.size())
        return true;
    
    int cnt = candidate.size();
    if (selected == (1 << cnt) - 1) 
        return false;
    
    for (int i = 0; i < cnt; i++) {
        int x = 1 << i;
        if (selected & x)
            continue;
        
        int next_dist = weak[weak_idx] + candidate[i];
        int idx = weak_idx;
        while(idx < weak.size() && weak[idx] <= next_dist) {
            idx++;
        }
        
        if (permutation(candidate, weak, idx, selected | x))
            return true;
    }
    return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    
    sort(dist.begin(), dist.end(), greater<int>());
    
    vector<int> candidate;
    for (int num = 1; num <= dist.size(); num++) {
        candidate.push_back(dist[num-1]);
        vector<int> new_weak = weak;
        
        for (int i = 0; i < weak.size(); i++) {
            
            if (permutation(candidate, new_weak, 0, 0)) {
                return num;
            }
            
            int front = new_weak[0];
            new_weak.erase(new_weak.begin(), new_weak.begin()+1);
            new_weak.push_back(front + n);
        }
        
    }
    return -1;
}