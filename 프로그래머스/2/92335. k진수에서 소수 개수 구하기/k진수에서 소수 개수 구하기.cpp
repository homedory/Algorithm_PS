#include <string>
#include <math.h>

using namespace std;

bool isPrime(long long n) {
    long long len = sqrt(n);
    if (n == 1)
        return false;
    
    for (int i = 2; i <= len; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

string convertToBase(int n, int k) {
    string base = "";
    while(n > 0) {
        base = to_string(n % k) + base;
        n /= k;
    }
    
    return base;
}

int solution(int n, int k) {
    int answer = 0;
    
    string base_num = convertToBase(n, k);
    
    int prev = 0;
    for (int i = 0; i <= base_num.length(); i++) {
        if (i == base_num.length() || base_num[i] == '0') {
            if (i > prev) {
                string num = base_num.substr(prev, i - prev);
                if (isPrime(stoll(num)))
                    answer++;
            }
            prev = i + 1;
        }
    }
    
    return answer;
}