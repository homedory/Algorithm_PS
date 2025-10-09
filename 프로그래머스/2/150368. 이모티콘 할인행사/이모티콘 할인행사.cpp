#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> user;
vector<int> emoticon;
vector<pair<int,int>> result;

pair<int,int> calcResult(vector<int> discount) {
    int membership_cnt = 0;
    int total_sales = 0;
    for (auto u : user) {
        int sum = 0;
        for (int i = 0; i < discount.size(); i++) {
            if (discount[i] >= u[0]) {
                sum += emoticon[i] / 100 * (100 - discount[i]);
            }
        }
        if (sum >= u[1]) {
            membership_cnt++;
        }
        else {
            total_sales += sum;
        }
    }
    
    return make_pair(membership_cnt, total_sales);
}

void select(vector<int> discount, int length) {
    
    if (discount.size() == length) {
        result.push_back(calcResult(discount));
        return;
    }
    
    int dis_rate[4] = {10, 20, 30, 40};
    
    for (int i = 0; i < 4; i++) {
        discount.push_back(dis_rate[i]);
        select(discount, length);
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    user = users;
    emoticon = emoticons;
    
    
    vector<int> discount;
    
    select(discount, emoticons.size());
    sort(result.begin(), result.end());
    
    auto [membership_cnt, sales] = result.back();
    
    answer.push_back(membership_cnt);
    answer.push_back(sales);
    return answer;
}