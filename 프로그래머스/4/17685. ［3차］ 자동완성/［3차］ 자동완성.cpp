#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countCommonChar(string s1, string s2) {
    int end = min(s1.length(), s2.length());
    for (int i = 0; i < end; i++) {
        if (s1[i] != s2[i])
            return i;
    }
    return end;
}

int solution(vector<string> words) {
    int answer = 0;
    
    sort(words.begin(), words.end());
    
    for (int i = 0; i < words.size(); i++) {
        int commons = 0;
        if (i > 0) {
            commons = max(commons, countCommonChar(words[i-1], words[i]));
        }
        
        if (i < words.size() - 1) {
            commons = max(commons, countCommonChar(words[i+1], words[i]));
        }
        
        if (commons != words[i].length())
            commons += 1;
        
        answer += commons;
    }
    return answer;
}