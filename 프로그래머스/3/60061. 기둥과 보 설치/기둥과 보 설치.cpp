#include <string>
#include <vector>

using namespace std;


bool checkRoofCond(vector<vector<int>> &roof, vector<vector<int>> &pillar, int x, int y, int n) {
    if (y > 0 && pillar[x][y-1] == 1 ||(x < n && pillar[x+1][y-1] == 1))
        return true;
    
    if (x < n && x > 0 && roof[x-1][y] == 1 && roof[x+1][y] == 1)
        return true;
    
    return false;
}

bool checkPillarCond(vector<vector<int>> &roof, vector<vector<int>> &pillar, int x, int y, int n) {
    if (y == 0 || pillar[x][y-1] == 1)
        return true;
    
    if (roof[x][y] == 1 || (x > 0 && roof[x-1][y] == 1))
        return true;
        
    return false;
}

bool checkPillarDelete(vector<vector<int>> &roof, vector<vector<int>> &pillar, int x, int y, int n) {
    pillar[x][y] = 0;
    
    if (pillar[x][y+1] == 1 && !checkPillarCond(roof, pillar, x, y+1, n)) {
        pillar[x][y] = 1;
        return false;
    }
    
    if (roof[x][y+1] == 1 && !checkRoofCond(roof, pillar, x, y+1, n)) {
        pillar[x][y] = 1;
        return false;
    }
    
    if (x > 0 && roof[x-1][y+1] == 1 && !checkRoofCond(roof, pillar, x-1, y+1, n)) {
        pillar[x][y] = 1;
        return false;
    }
    
    pillar[x][y] = 1;
    return true;
}

bool checkRoofDelete(vector<vector<int>> &roof, vector<vector<int>> &pillar, int x, int y, int n) {
    roof[x][y] = 0;
    
    if (pillar[x][y] == 1 && !checkPillarCond(roof, pillar, x, y, n)) {
        roof[x][y] = 1;
        return false;
    }
    
    if (x < n && pillar[x+1][y] == 1 && !checkPillarCond(roof, pillar, x+1, y, n)) {
        roof[x][y] = 1;
        return false;
    }
    
    if (x > 0 && roof[x-1][y] == 1 && !checkRoofCond(roof, pillar, x-1, y, n)) {
        roof[x][y] = 1;
        return false;
    }
    
    if (x < n && roof[x+1][y] == 1 && !checkRoofCond(roof, pillar, x+1, y, n)) {
        roof[x][y] = 1;
        return false;
    }

    roof[x][y] = 1;
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> pillar(n+1, vector<int> (n+1, 0));
    vector<vector<int>> roof(n+1, vector<int> (n+1, 0));
    
    for (auto command : build_frame) {
        int x = command[0];
        int y = command[1];
        int a = command[2];
        int b = command[3];
        
        if (b == 0) { // 삭제
            if (a == 0) { // 기둥
                if (checkPillarDelete(roof, pillar, x, y, n)) {
                    pillar[x][y] = 0;
                }
            }
            else { // 보
                if (checkRoofDelete(roof, pillar, x, y, n)) {
                    roof[x][y] = 0;
                }
            }
        } 
        else { // 설치
            if (a == 0) { // 기둥
                if (checkPillarCond(roof, pillar, x, y, n)) {
                    pillar[x][y] = 1;
                }
            }
            else { // 보
                if (checkRoofCond(roof, pillar, x, y, n)) {
                    roof[x][y] = 1;
                }
            }
        } 
    }
    
    vector<vector<int>> answer;
    
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (pillar[x][y] == 1) {
                vector<int> v;
                v.push_back(x);
                v.push_back(y);
                v.push_back(0);
                answer.push_back(v);
            }
            
            if (roof[x][y] == 1) {
                vector<int> v;
                v.push_back(x);
                v.push_back(y);
                v.push_back(1);
                answer.push_back(v);
            }
        }
    }
    
    
    return answer;
}