#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    //1. token 분리하기
    vector<string> temp, element;
    map<string, int> tuple;
    
    stringstream str(s);
    string arr;
    while(getline(str, arr, '{')) {
        temp.push_back(arr);
    }
    
    for(int i = 0; i < temp.size(); i++) {
        stringstream str(temp[i]);
        string arr;
        while(getline(str, arr, '}')) {
            if(arr.compare(",")!=0) {
                element.push_back(arr);
            }
        }
    }
    
    //2. map에 원소 개수 넣기
    for(int i = 0; i < element.size(); i++) {
        stringstream str(element[i]);
        string arr;
        while(getline(str, arr, ',')) {
            tuple[arr]++;
        }
    }
    
    //3. 개수 내림차순으로 정렬하기
    vector<pair<int, int>> sorted;
    for(auto& dic : tuple) {
        sorted.push_back(make_pair(stoi(dic.first), dic.second));
    }
    sort(sorted.begin(), sorted.end(), cmp);
    
    //4. answer 넣기
    for(int i = 0; i < sorted.size(); i++) {
        answer.push_back(sorted[i].first);
    }
    return answer;
}