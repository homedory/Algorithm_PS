#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    unordered_map<string, int> count;
    for (auto g : gems) {
        count[g] = 0;
    }
    
    int totalType = count.size();
    
    int left = 0, right = 0;
    int typeCnt = 0;
    int min_len = gems.size() + 1;
    
    while(left < gems.size()) {
        while(right < gems.size() && typeCnt < totalType) {
            if (count[gems[right]] == 0) {
                typeCnt++;
            }
            count[gems[right]] += 1;
            right++;
        }
        
        if (typeCnt == totalType && min_len > right - left) {
            min_len = right - left;
            answer.clear();
            answer.push_back(left + 1);
            answer.push_back(right);
        }
        
        
        count[gems[left]] -= 1;
        if (count[gems[left]] == 0) {
            typeCnt--;
        }
        left++;
    }
    
    return answer;
}