#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string,int> to_idx;
unordered_map<int, vector<int>> scores;

int getId(string lang, string field, string level, string food) {
    int idx = 1;
    int id = 0;
    
    id += idx * (1 << to_idx[food]);
    idx *= 10;
    
    id += idx * (1 << to_idx[level]);
    idx *= 10;
    
    id += idx * (1 << to_idx[field]);
    idx *= 10;
    
    id += idx * (1 << to_idx[lang]);
    
    return id;
}

int getId(int lang, int field, int level, int food) {
    int idx = 1;
    int id = 0;
    
    id += idx * (1 << food);
    idx *= 10;
    
    id += idx * (1 << level);
    idx *= 10;
    
    id += idx * (1 << field);
    idx *= 10;
    
    id += idx * (1 << lang);
    
    return id;
}

void dfs(vector<string> query, vector<int> selected, int &sum, int min_score) {
    if (selected.size() == 4) {
        int id = getId(selected[0], selected[1], selected[2], selected[3]);
        
        if (scores.find(id) == scores.end())
            return;
        
        int idx = lower_bound(scores[id].begin(), scores[id].end(), min_score) - scores[id].begin();
        
        sum += scores[id].size() - idx;
        return;
    }
    
    
    if (selected.size() == 0) { // lang
        if (query[0] == "-") {
            for (int i = 0; i < 3; i++) {
                selected.push_back(i);
                dfs(query, selected, sum, min_score);
                selected.pop_back();
            }
        }
        else {
            selected.push_back(to_idx[query[0]]);
            dfs(query, selected, sum, min_score);
            selected.pop_back();
        }
    } else if (selected.size() == 1) { // field
        if (query[1] == "-") {
            for (int i = 0; i < 2; i++) {
                selected.push_back(i);
                dfs(query, selected, sum, min_score);
                selected.pop_back();
            }
        }
        else {
            selected.push_back(to_idx[query[1]]);
            dfs(query, selected, sum, min_score);
            selected.pop_back();
        }
    } else if (selected.size() == 2) { // level
        if (query[2] == "-") {
            for (int i = 0; i < 2; i++) {
                selected.push_back(i);
                dfs(query, selected, sum, min_score);
                selected.pop_back();
            }
        }
        else {
            selected.push_back(to_idx[query[2]]);
            dfs(query, selected, sum, min_score);
            selected.pop_back();
        }
    } else if (selected.size() == 3) { // food
        if (query[3] == "-") {
            for (int i = 0; i < 2; i++) {
                selected.push_back(i);
                dfs(query, selected, sum, min_score);
                selected.pop_back();
            }
        }
        else {
            selected.push_back(to_idx[query[3]]);
            dfs(query, selected, sum, min_score);
            selected.pop_back();
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    to_idx["cpp"] = 0;
    to_idx["java"] = 1;
    to_idx["python"] = 2;
    to_idx["frontend"] = 0;
    to_idx["backend"] = 1;
    to_idx["junior"] = 0;
    to_idx["senior"] = 1;
    to_idx["chicken"] = 0;
    to_idx["pizza"] = 1;
    
    
    string lang, field, level, food, score, and1, and2, and3;
    
    for (auto inf : info) {
        stringstream ss(inf);
        ss >> lang >> field >> level >> food >> score;
        int id = getId(lang, field, level, food);
        scores[id].push_back(stoi(score));
    }
    
    for (auto &[id, vec] : scores) {
        sort(vec.begin(), vec.end());
    }
    
    for (auto q : query) {
        stringstream ss(q);
        ss >> lang >> and1 >> field >> and2 >> level >> and3 >> food >> score;
        
        int sum = 0;
        vector<string> vec;
        vec.push_back(lang);
        vec.push_back(field);
        vec.push_back(level);
        vec.push_back(food);
        
        vector<int> empty_vec;
        
        dfs(vec, empty_vec, sum, stoi(score));
        answer.push_back(sum);
    }
    
    
    return answer;
}