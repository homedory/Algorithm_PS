#include <string>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

int parent[2505];
string value[2505];
vector<int> child[2505];

int find(int cur) {
    if (parent[cur] == cur)
        return cur;
    
    return find(parent[cur]);
}


void changeValue(int p, string val) {
    if (val.empty())
        return;
    
    queue<int> q;
    
    q.push(p);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        value[cur] = val;
        
        for (auto c : child[cur]) {
            q.push(c);
        }
    }
}

void update(int pos, string val) {
    int p = find(pos);
    changeValue(p, val);
}

void update(string val1, string val2) {
    for (int i = 0; i < 2500; i++) {
        if (value[i] == val1)
            value[i] = val2;
    }
}

void unmerge(int pos) {
    string cur_value = value[pos];
    
    int p = find(pos);
    
    queue<int> q;
    
    q.push(p);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        value[cur].clear();
        parent[cur] = cur;
        
        for (auto c : child[cur]) {
            q.push(c);
        }
        child[cur].clear();
    }
    
    value[pos] = cur_value;
}



void merge(int a, int b) {
    string next_value = "";
    if (!value[a].empty()) {
        next_value = value[a];
    }
    else if (!value[b].empty()) {
        next_value = value[b];
    }    
    
    int a_parent = find(a);
    int b_parent = find(b);
    
    if (a_parent == b_parent) {
        return;
    }
    
    parent[b_parent] = a_parent;
    child[a_parent].push_back(b_parent);
    
    changeValue(a_parent, next_value);
}

auto split = [](const string& s){
    vector<string> t;
    string cur; 
    for (char ch : s) {
        if (ch==' ') { if(!cur.empty()){ t.push_back(cur); cur.clear(); } }
        else cur.push_back(ch);
    }
    if(!cur.empty()) t.push_back(cur);
    return t;
};

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 0; i < 2500; i++) {
        parent[i] = i;
    }
    
    for (auto c : commands) {
        int idx = c.find(' ');
        string command = c.substr(0, idx);
        string left_command = c.substr(idx+1);
        
        if (command == "UPDATE") {
            auto tok = split(left_command);
            if (tok.size() == 3) {                 
                int r = stoi(tok[0]), c = stoi(tok[1]);
                string val = tok[2];
                update((r-1)*50 + (c-1), val);
            } else {                                
                update(tok[0], tok[1]);
            }
        }
        else if (command == "MERGE") {
            idx = left_command.find(' ');
            int r1 = stoi(left_command.substr(0, idx));
            int idx2 = left_command.find(' ', idx + 1);
            int c1 = stoi(left_command.substr(idx + 1, idx2 - idx - 1));
            
            left_command = left_command.substr(idx2 + 1);
            idx = left_command.find(' ');
            int r2 = stoi(left_command.substr(0, idx));
            int c2 = stoi(left_command.substr(idx+1));
            
            merge((r1-1)*50 + (c1-1), (r2-1)*50 + (c2-1));
        }
        else if (command == "UNMERGE") {
            idx = left_command.find(' ');
            int r = stoi(left_command.substr(0, idx));
            int c = stoi(left_command.substr(idx+1));
            
            unmerge((r-1)*50 + (c-1));
        }
        else if (command == "PRINT") {
            idx = left_command.find(' ');
            int r = stoi(left_command.substr(0, idx));
            int c = stoi(left_command.substr(idx+1));
            
            int pos = (r-1)*50 + (c-1);
            
            if (value[pos].empty()) {
                answer.push_back("EMPTY");
            }
            else {
                answer.push_back(value[pos]);
            }
        }
    }
    
    return answer;
}