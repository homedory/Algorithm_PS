#include <string>
#include <vector>
#include <map>
using namespace std;

int convertDate(string str) {
    int year_idx = str.find('.');
    int year = stoi(str.substr(0, year_idx));
    int month = stoi(str.substr(year_idx + 1, 2));
    int date = stoi(str.substr(year_idx + 4, 2));
    
    return year * 12 * 28 + month * 28 + date;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<string,int> term;
    
    for (auto t : terms) {
        int idx = t.find(' ');
        string type = t.substr(0, idx);
        int duration = stoi(t.substr(idx + 1));
        term[type] = duration * 28;
    }
    
    int cur_date = convertDate(today);
    
    int p_idx = 1;
    for (auto p : privacies) {
        int idx = p.find(' ');
        string date = p.substr(0, idx);
        string type = p.substr(idx+1);
        if (cur_date >= convertDate(date) + term[type])
            answer.push_back(p_idx);
            
        p_idx++;
    }
    
    return answer;
}