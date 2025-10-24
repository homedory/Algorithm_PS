#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string convertToStart(string str) {
    string new_str = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '?') {
            new_str += "a";
        }
        else {
            new_str += str[i];
        }
    }
    return new_str;
}

string convertToEnd(string str) {
    string new_str = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '?') {
            new_str += "z";
        }
        else {
            new_str += str[i];
        }
    }
    return new_str;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    unordered_map<int, vector<string>> backward_word, forward_word;
    
    for (auto w : words) {
        int len = w.length();
        forward_word[len].push_back(w);
        
        reverse(w.begin(), w.end());
        backward_word[len].push_back(w);
    }
    
    for (auto& [len, w] : forward_word) {
        sort(w.begin(), w.end());
    }
    
    for (auto& [len, w] : backward_word) {
        sort(w.begin(), w.end());
    }
    
    for (auto q : queries) {
        string keyword = q;
        int len = q.length();
        
        if (q[0] == '?') {
            reverse(keyword.begin(), keyword.end());
        }
        
        string start = convertToStart(keyword);
        string end = convertToEnd(keyword);
        
        int cnt = 0;
        if (q[0] == '?') {
            cnt = upper_bound(backward_word[len].begin(), backward_word[len].end(), end) - lower_bound(backward_word[len].begin(), backward_word[len].end(), start);
        }
        else {
            cnt = upper_bound(forward_word[len].begin(), forward_word[len].end(), end) - lower_bound(forward_word[len].begin(), forward_word[len].end(), start);
        }
        answer.push_back(cnt);
    }
    
    return answer;
}