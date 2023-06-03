#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    
    for(int i = 0; i < 26; i++) {
        string temp ="";
        temp += char('A' + i);
        dic[temp] = i + 1;
    }
    
    int idx = 27;
    for(int i = 0; i < msg.size(); i++) {
        string temp = "";
        string cur;
        temp += msg[i];
        cur = temp;
        temp += msg[i+1];
        
        int j = i + 2;
        while(dic.find(temp) != dic.end()) {
            cur = temp;
            temp += msg[j++];
            i++;
        }
        dic[temp] = idx++;
        answer.push_back(dic[cur]);
    }
    
    return answer;
}