#include <string>
#include <vector>

using namespace std;

string dict[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8" ,"9", "A", "B", "C", "D", "E", "F"};

string convertNumber(int x, int n) {
    if (x == 0)
        return "0";
    
    string str = "";
    
    while(x > 0) {
        str = dict[x % n] + str;
        x /= n;
    }
    
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string order = "";
    int x = 0;
    
    int num = 0;
    while(num < t * m) {
        order += convertNumber(num, n);
        num++;
    }
    
    for (int i = 0; i < t; i++) {
        int idx = p + i * m - 1;
        
        answer += order[idx];
    }
    
    return answer;
}