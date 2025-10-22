#include <string>
#include <vector>

using namespace std;


bool isCorrect(string str) {    
    int cnt = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            cnt++;
        }
        else {
            cnt--;
        }
        
        if (cnt < 0)
            return false;
    }
    return true;
}

pair<string,string> splitString(string str) {
    int idx = 1;
    int cnt = str[0] == '(' ? 1 : -1;
    while (idx < str.length() && cnt != 0) {
        cnt += (str[idx] == '(' ? 1 : -1);
        idx++;
    }
    
    string u = str.substr(0, idx);
    string v = str.substr(idx);
    return {u, v};
}

string removeAndReverse(string str) {
    string result = "";
    
    for (int i = 1; i < str.length()-1; i++) {
        if (str[i] == '(') {
            result += ")";
        }
        else {
            result += "(";
        }
    }
    return result;
}

string solve(string str) {
    if (str.empty())
        return "";
    
    auto [u, v] = splitString(str);
    
    if (isCorrect(u)) {
        return u + solve(v);
    }
    
    return "(" + solve(v) + ")" + removeAndReverse(u);
}

string solution(string p) {
    
    return solve(p);
}