#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int, int>> tuple;
    priority_queue<int> q;
    
    vector<string> token;
    stringstream str(s);
    string arr;
    while(getline(str, arr, '{')) {
        if(arr.compare("\0")) {
            token.push_back(arr);
        }
    }
    for(int i = 0; i < token.size(); i++) {
        stringstream str2(token[i]);
        string arr2;
        while(getline(str2, arr2, '}')) {
            if(arr2.compare("\0") && arr2.compare(",")) {
                //cout << arr2 << ' ';
                token[i] = arr2;
                //cout << token[i] << '\n';
            }
        }
    }
    
    for(int i = 0; i < token.size(); i++) {
        tuple.push_back(make_pair(i,token[i].size()));
        //q.push(token[i].size());
    }
    sort(tuple.begin(), tuple.end(), cmp);
    
    for(int i = tuple.size() - 1; i >= 0; i--) {
        cout << token[tuple[i].first] << '\n';
        //string gg = token[tuple[i].first];
        
    }
    
    /*
    int idx = tuple[0].first;
    cout << token[idx];
    stringstream str3(token[idx]);
    string arr3;
    
    while(getline(str3, arr3, ",")) {
        answer.push_back(stoi(arr3));
        cout << arr3 << ' ';
    }
    */
    
    return answer;
}