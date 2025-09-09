#include <string>
#include <vector>

using namespace std;

int solution(int coin, vector<int> cards) {
    int position[1005];
    int n = cards.size();
    
    for (int i = 0; i < n; i++) {
        position[cards[i]] = i;
    }
    
    int cost[3] = {0, 0, 0};
    
    int bound = n / 3;
    
    for (int i = 0; i < bound; i++) {
        int pair_num = n + 1 - cards[i];
        if (position[pair_num] > i)
            continue;
        
        cost[0]++;
    }
    
    int round = 1;
    
    for (int i = bound; i < n; i += 2) {
        for (int j = 0; j < 2; j++) {
            int pair_num = n + 1 - cards[i+j];
            
            if (position[pair_num] > i+j)
                continue;
            
            if (position[pair_num] < bound) {
                cost[1]++;
            }
            else {
                cost[2]++;
            }
        }
        
        bool end = true;
        for (int j = 0; j < 3; j++) {
            if (cost[j] > 0 && coin >= j) {
                cost[j]--;
                coin -= j;
                end = false;
                break;
            }
        }
        
        if (end)
            break;
        
        round++;
    }
    
    return round;
}