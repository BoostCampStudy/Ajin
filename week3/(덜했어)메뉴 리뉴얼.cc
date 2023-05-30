#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void get_substr(string order, vector<char> comb, int r, int index, int depth);

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    int r = orders[0].size();
    vector<char> comb(r);
    
    for(int i = 0; i < course.size(); i++) {
        get_substr(orders[0], comb, course[i], 0, 0);
    }
    return answer;
}

void get_substr(string order, vector<char> comb, int r, int index, int depth) {
    if(r == 0) {
        for(int i = 0; i < comb.size(); i++) {
            cout << comb[i] << ' ';
        }
        cout << '\n';
    }
    else if(depth == substr.size()) {
        return;
    }
    else {
        comb[index] = substr[depth];
        get_substr(substr, comb, r - 1, index + 1, depth + 1);
        get_substr(substr, comb, r, index, depth + 1);
    }
}