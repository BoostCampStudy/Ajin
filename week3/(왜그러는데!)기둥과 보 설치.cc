#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool install_frame(int x, int y, int type);
bool remove_frame(int x, int y, int type);

vector<vector<bool>> zero, one;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    zero.resize(n+1, vector<bool>(2));
    one.resize(n+1, vector<bool>(2));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            zero[i][j] = one[i][j] = false;
        }
    }
    
    for(int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int type = build_frame[i][2]; // 0: 기둥, 1: 보
        
        if(build_frame[i][3] == 1) { //설치
            bool is_okay = install_frame(x, y, type);
            if(type == 0) {
                zero[x][y] = is_okay;
            }
            else {
                one[x][y] = is_okay;
            }
        }
        else { //삭제
            bool not_remove = remove_frame(x, y, type); //return이 false면 배열을 true로
            if(type == 0) {
                zero[x][y] = !not_remove;
            }
            else {
                one[x][y] = !not_remove;
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

bool install_frame(int x, int y, int type) {
    if(type == 0) { //기둥 설치
        if(y == 0) { //기둥 조건1: 바닥 위는 모두 설치 가능
            return true;
        }
        else if(one[x][y] || one[x-1][y]) { //기둥 조건2: 보의 한 쪽 끝의 위라면 설치 가능
            return true;
        }
        else if(zero[x][y-1]) { //기둥 조건3: 다른 기둥의 위쪽이라면 설치 가능
            return true;
        }
        else {
            return false;
        }
    }
    else { //보 설치
        if(zero[x][y-1] || zero[x+1][y-1]) { // 보 조건1: 한 쪽 끝이 기둥 위라면 설치 가능
            return true;   
        }
        else if(one[x-1][y] && one[x+1][y]) { // 보 조건2: 양쪽 끝이 다른 보와 연결되면 설치 가능
            return true;
        }
        else {
            return false;
        }
    }
}

bool remove_frame(int x, int y, int type) {
    if(type == 0) { // 기둥 제거
        zero[x][y] = false;
        
        //위쪽 기둥 괜찮아?
        if(zero[x][y+1] && !install_frame(x,y+1,0)) {
            return false;
        }
        
        //위쪽 보 괜찮아?
        if(one[x][y+1] && !install_frame(x, y+1,1)) { 
            return false;
        }
        if(one[x-1][y+1] && !install_frame(x-1, y+1,1)) {
            return false;
        }
    }
    else { // 보 제거
        one[x][y] = false;
        
        //위쪽 기둥 괜찮아?
        if(zero[x][y] && install_frame(x,y,0)) {
            return false;
        }
        if(zero[x+1][y] && install_frame(x+1, y, 0)) {
            return false;
        }
        
        //양쪽 보 괜찮아?
        if(one[x-1][y] && install_frame(x-1, y, 1)) {
            return false;
        }
         if(one[x+1][y] && install_frame(x+1, y, 1)) {
            return false;
        }
    }
    return true;
}