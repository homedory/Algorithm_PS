#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    int max_l = s.length() / 2;
    
    for (int l = 1; l <= max_l; l++) {
        
        string prev = "";
        int cnt = 0;
        string result = "";
        
        for (int i = 0; i < s.length(); i += l) {
            string cur = s.substr(i, min(l, (int)s.length() - i));
            if (cur == prev) {
                cnt++;
            }
            else {
                if (cnt > 1) {
                    result += to_string(cnt);
                }
                result += prev;
                prev = cur;
                cnt = 1;
            }
        } 
        if (cnt > 1) {
            result += to_string(cnt);
        }
        result += prev;
        
        answer = min(answer, (int)result.length());
    }
    
    return answer;
}