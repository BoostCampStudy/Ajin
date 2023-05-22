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
    
    //1. 경계값 처리하기 -> 실패
    
    //2. end 순으로 정렬하기
    sort(targets.begin(), targets.end(), cmp);
    
    //3. 겹치는 거 찾기
    int nextidx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(targets[i][1] - 1 > targets[j][0]) {
                nextidx = j;
            }
            else {
                answer++;
                i = nextidx;
                break;
            }
        }
    }
    
    return answer;
}