#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    map<string,int> tuple;
    string tmp;

    for(char i: s) {
        if(i-'0' >= 0 && i-'0' <= 9) {
            tmp += i;
        }
        else {
            if(tmp.length()) {
                tuple[tmp]++;
                tmp.clear();
            }
        }
    }

    vector<pair<int,int>> sorted;
    for(auto iter = tuple.begin(); iter != tuple.end(); iter++) {
        sorted.push_back(make_pair(iter->second, stoi(iter->first)));
    }                       
    sort(sorted.begin(), sorted.end());
    reverse(sorted.begin(), sorted.end());

    for(auto iter: sorted) {
        answer.push_back(iter.second);
    } 

    return answer;
}