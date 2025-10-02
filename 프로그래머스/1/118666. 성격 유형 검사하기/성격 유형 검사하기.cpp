#include <string>
#include <vector>
#include <unordered_map>

using namespace std;



string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char,int> score;
    
    char types[8] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    for (int i = 0; i < 8; i++) {
        score[types[i]] = 0;
    }
    
    
    for (int i = 0; i < survey.size(); i++) {
        char opt1 = survey[i][0];
        char opt2 = survey[i][1];
        
        int choice = choices[i];
        
        if (choice < 4) {
            score[opt1] = score[opt1] + 4 - choice;
        }
        else if (choice > 4) {
            score[opt2] = score[opt2] + choice - 4;
        }
        
    }
        
    for (int i = 0; i < 4; i++) {
        char opt1 = types[i * 2];
        char opt2 = types[i * 2 + 1];
        
        if (score[opt1] < score[opt2])
            answer += opt2;
        else
            answer += opt1;
    }
    
    return answer;
}