#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> dic;

void get_substr(string order, vector<char> comb, int r, int index, int depth);
bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());

        for(int j = 0; j < course.size(); j++) {
            vector<char> comb(course[j]);
            get_substr(orders[i], comb, course[j], 0, 0);
        }
    }
    
    //map 정렬: 따로 pair 만들어서 하기
    vector<pair<string,int>> sorted;
    for(auto& order : dic) {
        if(order.second > 1) {
            sorted.push_back(make_pair(order.first, order.second));
        }
    }
    sort(sorted.begin(), sorted.end(), cmp);
    
    //개쩐다 조건을 어떻게 이렇게 깔끔하게 나눔? 미친
    for(int i = 0; i < course.size(); i++) {
        int max = 0;
        for(int j = 0; j < sorted.size(); j++) {
            if(sorted[j].first.length() != course[i]) {
                continue;
            }
            else if(max == 0) {
                answer.push_back(sorted[j].first);
                max = sorted[j].second;
            }
            else if(max == sorted[j].second) {
                answer.push_back(sorted[j].first);
            }
            else {
                break;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

void get_substr(string order, vector<char> comb, int r, int index, int depth) {
    if(r == 0) {
        string tada;
        for(int i = 0; i < comb.size(); i++) {
            tada += comb[i];
        }
        
        dic[tada]++;
    }
    else if(depth == order.size()) {
        return;
    }
    else {
        comb[index] = order[depth];
        get_substr(order, comb, r - 1, index + 1, depth + 1);
        get_substr(order, comb, r, index, depth + 1);
    }
}