#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getHeadLength(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            return i;
    }
    return s.length();
}

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' + 'a');
    }
    return s;
}

int getNumberLength(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return i;
    }
    return s.length();
}

bool comparator(const string &s1, const string &s2) {
    int head_length1 = getHeadLength(s1);
    int head_length2 = getHeadLength(s2);
    
    string head1 = toLower(s1.substr(0, head_length1));
    string head2 = toLower(s2.substr(0, head_length2));
    
    if (head1 != head2) {
        return head1 < head2;    
    }
    
    int number_length1 = getNumberLength(s1.substr(head_length1));
    int number_length2 = getNumberLength(s2.substr(head_length2));
    
    int number1 = stoi(s1.substr(head_length1, number_length1));
    int number2 = stoi(s2.substr(head_length2, number_length2));
    
    return number1 < number2;
    
}


vector<string> solution(vector<string> files) {
    
    stable_sort(files.begin(), files.end(), comparator);
    
    return files;
}