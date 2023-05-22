#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1]) {
        return v1[0] < v2[0];
    }
    else {
        return v1[1] < v2[1];
    }
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int n = targets.size();
    
    //1. end 순으로 정렬하기
    sort(targets.begin(), targets.end(), cmp);
    
    //2. 겹치는 거 찾기
    int i = 0;
    while(i < n) {
        int nextidx = targets[i++][1];
        answer++;
        while (i < n && targets[i][0] < nextidx) {
            if (targets[i][1] < nextidx) {
                nextidx = targets[i][1];
            }
            i++;
        }
    }
    
    return answer;
}