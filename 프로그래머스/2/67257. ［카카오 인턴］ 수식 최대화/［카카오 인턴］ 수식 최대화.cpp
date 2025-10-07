#include <string>
#include <vector>

using namespace std;

long long answer = 0;
vector<string> expr;


void calculate(string op) {
    for (int i = 1; i < expr.size(); i += 2) {
        if (expr[i] == op) {
            long long result = 0;
            
            if (op == "*") {
                result = stoll(expr[i-1]) * stoll(expr[i+1]);
            }
            else if (op == "-") {
                result = stoll(expr[i-1]) - stoll(expr[i+1]);
            }
            else {
                result = stoll(expr[i-1]) + stoll(expr[i+1]);
            }
            
            expr[i-1] = to_string(result);
            expr.erase(expr.begin() + i, expr.begin() + i + 2);
            i -= 2;
        }
    }
}

void perm(int selected) {
    string op[3] = {"*", "+", "-"};
    
    if (selected == 7) {
        answer = max(answer, abs(stoll(expr[0])));
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        int x = 1 << i;
        if ((selected & x) == 0) {
            
            vector<string> temp = expr;
            calculate(op[i]);
            perm(selected | x);
            expr = temp;
        }
    }
}

long long solution(string expression) {
    int left = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+') {
            expr.push_back(expression.substr(left, i - left));
            left = i + 1;
            string str = "";
            expr.push_back(str + expression[i]);
        }
        else if (i == expression.length() - 1) {
            expr.push_back(expression.substr(left, i - left + 1));
        }
    }
    perm(0);

    return answer;
}