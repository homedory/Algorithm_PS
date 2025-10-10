#include <string>
#include <vector>
#include <cctype>

using namespace std;

string phase1(string id) {
    for (int i = 0; i < id.length(); i++) {
        if (id[i] - 'A' >= 0 && id[i] - 'A' < 26) {
            id[i] = 'a' + (id[i] - 'A');
        }
    }
    return id;
}

string phase2(string id) {
    string new_id = "";
    for (int i = 0; i < id.length(); i++) {
        if (id[i] - 'a' >= 0 && id[i] - 'a' < 26) {
            new_id += id[i];
        }
        else if (isdigit(id[i]) || id[i] == '-' || id[i] == '_' || id[i] == '.') {
            new_id += id[i];
        }
    }
    return new_id;
}

string phase3(string id) {
    string new_id = "";
    
    bool prev_dot = false;
    
    for (int i = 0; i < id.length(); i++) {
        if (id[i] == '.') {
            if (!prev_dot)
                new_id += id[i];    
            
            prev_dot = true;
        }
        else {
            new_id += id[i];
            prev_dot = false;
        }
    }
    return new_id;
}

string phase4(string id) {
    string new_id = "";
    if (id.length() > 0) {
        if (id[0] == '.') {
            new_id = id.substr(1);
        }
        else {
            new_id = id;
        }
    }
    
    if (new_id.length() > 0) {
        if (new_id[new_id.length()-1] == '.') {
            new_id = new_id.substr(0, new_id.length()-1);
        }
    }
    return new_id;
}

string phase5(string id) {
    if (id.empty()) {
        return "a";
    }
    return id;
}

string phase6(string id) {
    string new_id = id;
    if (id.length() >= 16) {
        new_id = id.substr(0, 15);
        
        if (new_id[14] == '.') {
            new_id = new_id.substr(0, 14);
        }
    }
    return new_id;
}

string phase7(string id) {
    if (id.length() <= 2) {
        char end = id[id.length()-1];
        while(id.length() < 3) {
            id += end;
        }
    }
    return id;
}

string solution(string new_id) {
    new_id = phase1(new_id);
    new_id = phase2(new_id);
    new_id = phase3(new_id);
    new_id = phase4(new_id);
    new_id = phase5(new_id);
    new_id = phase6(new_id);
    new_id = phase7(new_id);
    
    return new_id;
}