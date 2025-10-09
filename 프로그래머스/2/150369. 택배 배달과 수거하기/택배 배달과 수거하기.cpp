#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int pickup_idx = n - 1;
    int deliv_idx = n - 1;
    
    while(pickup_idx >= 0 || deliv_idx >= 0) {
        int pickup_cap = cap;
        int deliv_cap = cap;
        int max_idx = -1;
        while(deliv_cap > 0 && deliv_idx >= 0) {
            if (deliveries[deliv_idx] > 0)
                max_idx = max(max_idx, deliv_idx);
            
            int fill = min(deliveries[deliv_idx], deliv_cap);
            deliveries[deliv_idx] -= fill;
            
            if (deliveries[deliv_idx] == 0)
                deliv_idx--;
            
            deliv_cap -= fill;
        }
        
        while(pickup_cap > 0 && pickup_idx >= 0) {
            if (pickups[pickup_idx] > 0)
                max_idx = max(max_idx, pickup_idx);
            
            int fill = min(pickups[pickup_idx], pickup_cap);
            pickups[pickup_idx] -= fill;
            
            if (pickups[pickup_idx] == 0)
                pickup_idx--;
            
            pickup_cap -= fill;
        }
        
        answer += (max_idx + 1) * 2;
    }
    
    return answer;
}