#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> idx;
vector<bool> check;
int n, m, answer;
map<string, int> cnt;
void make_case(int depth);

int solution(vector<string> user_id, vector<string> banned_id) {
    idx.resize(banned_id.size());
    check.resize(user_id.size());
    n = banned_id.size();
    m = user_id.size();
    
    for(int i = 0; i < banned_id.size(); i++) {
        string ban_id = banned_id[i];
        
        for(int j = 0; j < user_id.size(); j++) {
            string cur_id = user_id[j];
            if(cur_id.size() != ban_id.size()) {
                continue;
            }
            
            bool check = false;
            for(int k = 0; k < cur_id.size(); k++) {
                if(ban_id[k] == '*') {
                    continue;
                }
                if(ban_id[k] != cur_id[k]) {
                    check = true;
                }
            }
            if(check == false) { // 재재 아이디다
                idx[i].push_back(j); //idx[ban_id_idx] = user_id_idx
            }
        }
    }
    make_case(0);
    
    answer = cnt.size();
    
    return answer;
}

void make_case(int depth) {
    //cout << '\n';
    if(depth == n) {
        string temp;
        for(int i = 0; i < m; i++) {
            if(check[i] == true) {
                temp += i;
            }
        }
        cnt[temp]++;
        //cout << "야호!\n";
        return;
    }
    
    bool pick = false;
    for(int i = 0; i < idx[depth].size(); i++) {
        //cout << depth << ' ' << i << ':';
        
        int cur_idx = idx[depth][i];
        //cout << cur_idx << ' ';
        
        if(check[cur_idx] == true) {
            //cout << "땡\n";
            continue;
        }
        else {
            check[cur_idx] = true;
            pick = true;
            //cout << "다음\n";
            make_case(depth+1);
            check[cur_idx] = false;
        }
    }
    if(pick == false) {
        fill(check.begin(), check.end(), false);
        return;
    }
}