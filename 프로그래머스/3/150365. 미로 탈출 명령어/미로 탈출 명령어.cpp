#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int horiz = c - y;
    int vertic = r - x;
    
    // d = {1, 0}
    // u = {-1, 0}
    // l = {-1, 0}
    // r = {1, 0}
    
    // int d_count
    // int u_count = d_count - vertic;
    // int l_count = r_count - horiz;
    
    // 2 * (d_count + l_count) = k + vertic + horiz;
    // 
    
    if (k - abs(vertic) - abs(horiz) < 0 || (k - abs(vertic) - abs(horiz)) % 2 == 1)
        return "impossible";
    
    int len = (k - abs(vertic) - abs(horiz)) / 2;
    
    int vertic_min_cnt = 0;
    int horiz_min_cnt = len - vertic_min_cnt;
    
    vector<string> candidate;
    while(horiz_min_cnt >= 0) {
        int d_count, u_count, r_count, l_count;
        if (vertic > 0) { // d_count가 더 큼
            d_count = vertic_min_cnt + vertic;
            u_count = vertic_min_cnt;
        }
        else {
            d_count = vertic_min_cnt;
            u_count = vertic_min_cnt + abs(vertic);
        }
        
        if (horiz > 0) {
            r_count = horiz_min_cnt + horiz;
            l_count = horiz_min_cnt;
        }
        else {
            r_count = horiz_min_cnt;
            l_count = horiz_min_cnt + abs(horiz);
        }
        
        
        queue<char> vertical_order;
        int cur_r = x;
        while(u_count > 0 || d_count > 0) {
            if (d_count > 0 && cur_r + 1 <= n) {
                vertical_order.push('d');
                cur_r++;
                
                d_count--;
            }
            else if (u_count > 0) {
                vertical_order.push('u');
                cur_r--;
                
                u_count--;
            }
        }
        
        queue<char> horizontal_order;
        int cur_c = y;
        while(l_count > 0 || r_count > 0) {
            if (l_count > 0 && cur_c - 1 > 0) {
                horizontal_order.push('l');
                cur_c--;
                
                l_count--;
            }
            else if (r_count > 0) {
                horizontal_order.push('r');
                cur_c++;
                
                r_count--;
            }
        }
        
        string str = "";
        while(!horizontal_order.empty() || !vertical_order.empty()) {
            if (!vertical_order.empty() && vertical_order.front() == 'd') {
                str.push_back('d');
                vertical_order.pop();
            }
            else if (!horizontal_order.empty()) {
                str.push_back(horizontal_order.front());
                horizontal_order.pop();
            }
            else if (!vertical_order.empty()) {
                str.push_back(vertical_order.front());
                vertical_order.pop();
            }
        }
        
        candidate.push_back(str);
        
        vertic_min_cnt++;
        horiz_min_cnt--;
    }
    
    if (candidate.size() == 0)
        return "impossible";
    
    sort(candidate.begin(), candidate.end());
    

    answer = candidate[0];
    
    return answer;
}