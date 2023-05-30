#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    bool zero[n+1][n+1], one[n+1][n+1];
    memset(zero, false, sizeof(zero));
    memset(one, false, sizeof(one));
    
    for(int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int type = build_frame[i][2]; // 0: 기둥, 1: 보
        
        if(build_frame[i][3] == 1) { //설치
            if(type == 0) { //기둥 설치
                if(y == 0) { //기둥 조건1: 바닥 위는 모두 설치 가능
                    zero[x][y] = true;
                }
                else if(one[x][y] || one[x-1][y]) { //기둥 조건2: 보의 한 쪽 끝의 위라면 설치 가능
                    zero[x][y] = true;
                }
                else if(zero[x][y-1]) { //기둥 조건3: 다른 기둥의 위쪽이라면 설치 가능
                    zero[x][y] = true;
                }
            }
            
            else { //보 설치
                if(zero[x][y-1] || zero[x+1][y-1]) { // 보 조건1: 한 쪽 끝이 기둥 위라면 설치 가능
                    one[x][y] = true;   
                }
                else if(one[x-1][y] && one[x+1][y]) { // 보 조건2: 양쪽 끝이 다른 보와 연결되면 설치 가능
                    one[x][y] = true;
                }
            }
        }
        else { //삭제
            if(type == 0) { //기둥 삭제
                zero[x][y] = false;
            }
            else {
                one[x][y] = true;
            }
        }
        
    }
    for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                vector<int> tuple;
                if(zero[i][j]) {
                    tuple.push_back(i);
                    tuple.push_back(j);
                    tuple.push_back(0);
                }
                else if(one[i][j]) {
                    tuple.push_back(i);
                    tuple.push_back(j);
                    tuple.push_back(1);
                }
                if(!tuple.empty()) {
                    answer.push_back(tuple);
                }
                tuple.clear();
            }
        }
    return answer;
}