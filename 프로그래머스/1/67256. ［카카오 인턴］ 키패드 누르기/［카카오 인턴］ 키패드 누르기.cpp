#include <string>
#include <vector>
#include <math.h>

using namespace std;

int getDistance(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> loc[12];
    for (int num = 1; num <= 9; num++) {
        loc[num] = {(num-1)/3, (num-1) % 3};
    }
    
    loc[0] = {3, 1};
    
    pair<int,int> left_hand = {3, 0};
    pair<int,int> right_hand = {3, 2};
    
    for (auto num : numbers) {
        if (num % 3 == 1) {
            left_hand = loc[num];
            answer += "L";
        }
        else if (num % 3 == 0 && num != 0) {
            right_hand = loc[num];
            answer += "R";
        }
        else {
            int left_dist = getDistance(loc[num], left_hand);
            int right_dist = getDistance(loc[num], right_hand);
            
            if (left_dist < right_dist) {
                left_hand = loc[num];
                answer += "L";
            }
            else if (left_dist > right_dist) {
                right_hand = loc[num];
                answer += "R";
            }
            else {
                if (hand == "left") {
                    left_hand = loc[num];
                    answer += "L";
                }
                else {
                    right_hand = loc[num];
                    answer += "R";
                }
            }
        }
    }
    return answer;
}