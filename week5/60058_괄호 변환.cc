#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    string answer = "";
    //step 1
    if(p == "") {
        return "";
    }

    //step 2
    vector<int> left_idx, right_idx;
    string temp, u, v, new_p;
    for(int i = 0; i < p.size(); i++) {
        if(p[i] == '(') {
            left_idx.push_back(i);
        }
        else {
            right_idx.push_back(i);
        }
        temp += p[i];
        if(left_idx.size() == right_idx.size()) {
            u = temp;
            v = p.substr(i+1, p.size() - i);
            break;
        }
    }

    //step 3
    int cnt = 0;
    bool check = false;
    for(int i = 0; i < u.size(); i++) {
        if(u[i] == '(') {
            cnt++;
        }
        else {
            cnt--;
        }
        if(cnt < 0) {
            check = true;
            break;
        }
    }
    
    if(check == false) { //올바른 문자열
        v = solution(v);
        answer = u + v;
        return answer;
    }
    else { //step 4
        answer = "(";
        answer += solution(v);
        answer = answer + ")";
        
        u.erase(0, 1);
        u.erase(u.size() -1, 1);
        
        for(int i = 0; i < u.size(); i++) {
            if(u[i] == '(') {
                answer += ')';
            }
            else {
                answer += '(';
            }
        }
    }
    
    return answer;
}