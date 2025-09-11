#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int,int> in_time; // <num,time>
unordered_map<int,int> accumulated_time; // <num,time>
int base_time, base_fee, unit_time, unit_fee;


int convertTime(string t) {
    int hour = stoi(t.substr(0, t.find(":")));
    int minute = stoi(t.substr(t.find(":") + 1));
    
    return hour * 60 + minute;
}

int calucateTotalFee(int time) {
    if (time <= base_time)
        return base_fee;
    
    int exceed_time  = time - base_time;
    return base_fee + ceil((double) exceed_time / unit_time) * unit_fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    base_time = fees[0];
    base_fee = fees[1];
    unit_time = fees[2];
    unit_fee = fees[3];
    
    for (auto rec : records) {
        string time, number, type;
        stringstream ss(rec);
        ss >> time >> number >> type;
        
        int num = stoi(number);
        
        if (type == "OUT") {
            if (accumulated_time.find(num) != accumulated_time.end())
                accumulated_time[num] = accumulated_time[num] + (convertTime(time) - in_time[num]);
            else
                accumulated_time[num] = convertTime(time) - in_time[num];
            
            in_time[num] = -1;
        }
        else {
            in_time[num] = convertTime(time);
        }
    }
    
    vector<int> num_list;
    for (auto it = in_time.begin(); it != in_time.end(); ++it) {
        num_list.push_back(it->first);
    }
    sort(num_list.begin(), num_list.end());
    
    for (auto num : num_list) {
        int total_time = accumulated_time[num];
        if (in_time[num] != -1) {
            total_time += (60 * 23 + 59) - in_time[num];
        }
        answer.push_back(calucateTotalFee(total_time));
    }
    
    
    return answer;
}