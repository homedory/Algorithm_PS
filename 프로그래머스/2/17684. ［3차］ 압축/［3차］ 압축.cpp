#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> dict;
    
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;
        string s;
        s += c;
        
        dict[s] = i + 1;
    }
    int idx = 27;
    
    int msg_length = msg.length();
    
    int pos = 0;
    while (pos < msg_length) {
        
        int len = 0;
        
        while (pos + len < msg_length && dict.find(msg.substr(pos, len + 1)) != dict.end()) {
            len++;    
        }
        
        answer.push_back(dict[msg.substr(pos, len)]);
        
        if (pos + len < msg_length) {
            dict[msg.substr(pos, len + 1)] = idx++;
        }
        
        pos += len;
    }
    
    return answer;
}