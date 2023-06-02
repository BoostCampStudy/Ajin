#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m = { {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9} };

int solution(string s) {
    string answer = "";
    string temp = "";
    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            answer += s[i];
        }
        else {
            temp += s[i];
        }
        
        if(m.find(temp) != m.end()) {
            answer += to_string(m[temp]);
            temp = "";
        }
    }

    return stoi(answer);
}