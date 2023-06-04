#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, user, comment;
    map<string, string> m;
    string type, id, name;
    
    for(int i = 0; i < record.size(); i++) {
        istringstream stt(record[i]);
        stt >> type >> id >> name;
        
        if(type.compare("Enter") == 0) {
            comment.push_back("님이 들어왔습니다.");
            user.push_back(id);
            m[id] = name;
        }
        else if(type.compare("Leave") == 0) {
            comment.push_back("님이 나갔습니다.");
            user.push_back(id);
        }
        else {
            m[id] = name;
        }
    }
    for(int i = 0; i < comment.size(); i++) {
        answer.push_back(m[user[i]] + comment[i]);
    }
    return answer;
}