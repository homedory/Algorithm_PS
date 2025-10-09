#include <string>
#include <vector>

using namespace std;

string convertToBinary(long long number) {
    string bin = "";
    while(number > 0) {
        bin = to_string(number % 2) + bin;
        number /= 2;
    }
    
    return bin;
}

string padZeros(string number) {
    int range[8] = {1, 3, 7, 15, 31, 63, 127, 253};
    
    int idx = 0;
    while(idx < 8 && range[idx] < number.length()) {
        idx++;
    }
    
    int len = range[idx];
    
    string result = "";
    for (int i = 0; i < len - number.length(); i++) {
        result += "0";
    }
    result = result + number;
    return result;
}



int divide(int left, int right, string expr, bool &ans) {
    if (left == right) {
        if (expr[left] == '0')
            return 0;
        else 
            return 1;
    }
    int mid = (left + right) / 2;
    int left_res = divide(left, mid-1, expr, ans);
    int right_res = divide(mid+1, right, expr, ans);
    
    if (expr[mid] == '0' && (left_res == 1 || right_res == 1)) {
        ans = false;
    }
    
    if (expr[mid] == '1') {
        return 1;
    }
    return 0;
}

bool isPossible(string expr) {
    bool answer = true;
    divide(0, expr.length() - 1, expr, answer);
    
    return answer;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (auto num : numbers) {
        if (isPossible(padZeros(convertToBinary(num)))) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }
    return answer;
}