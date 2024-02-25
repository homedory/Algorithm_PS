#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move_cnt = len;
    
    for (int i = 0; i < name.length(); i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int end = i + 1;
        
        while(end < len && name[end] == 'A') {
           end++; 
        }
        
        int l = min(i, len - end);
        
        move_cnt = min(move_cnt, i + len - end + l);
    }
    
    answer += move_cnt;
    
    return answer;
}