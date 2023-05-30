#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<vector<string>> people(info.size());
    for(int i = 0; i < info.size(); i++) {
        stringstream str(info[i]);
        string type;
        
        while(getline(str, type, ' ')) {
            people[i].push_back(type);
        }
    }
    
    for(int i = 0; i < query.size(); i++) {
        vector<string> pick;
        int cnt = 0;
        stringstream str(query[i]);
        string option;
        
        while(getline(str, option, ' ')) {
            if(!option.compare("and")) {
                continue;
            }
            pick.push_back(option);
        }
        
        for(int j = 0; j < people.size(); j++) {
            bool check = false;
            for(int k = 0; k < 4; k++){
                if(!pick[k].compare("-")) {
                    continue;
                }
                if(pick[k].compare(people[j][k])) {
                    check = true;
                    continue;
                }
            }
            if(!check) {
                if(stoi(pick[4]) <= stoi(people[j][4])) {
                    cnt++;
                }
            }
        }
        
        answer.push_back(cnt);
    }
    return answer;
}