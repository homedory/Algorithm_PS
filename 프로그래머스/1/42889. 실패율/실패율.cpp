#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    double fail_rate;
    int stage_num;
    
    bool operator < (const Data &other)const {
        if (fail_rate == other.fail_rate)
            return stage_num < other.stage_num;
        
        return fail_rate > other.fail_rate;
    }
};



vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    sort(stages.begin(), stages.end());
    
    vector<Data> vec; 
    for (int i = 1; i <= N; i++) {
        int total = stages.end() - lower_bound(stages.begin(), stages.end(), i);
        int failer = upper_bound(stages.begin(), stages.end(), i) - lower_bound(stages.begin(), stages.end(), i);
        double fail_rate = 0;
        
        if (total != 0) {
            fail_rate = (double) failer / (double) total;
        }
        vec.push_back({fail_rate, i});
    }
    sort(vec.begin(), vec.end());
    
    for (auto d : vec) {
        answer.push_back(d.stage_num);
    }
    
    return answer;
}