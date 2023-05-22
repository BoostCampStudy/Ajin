#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int leftCnt, rightCnt;

int solution(string name) {
    int answer = 0;
    leftCnt = rightCnt = name.size() - 1;
    
    for(int i = 0; i < name.size(); i++) {
        int updown = name[i] - 'A';
        if(name[i] - 'A' > 13) {
            updown = 26 - updown;
        }
        rightCnt += updown;
    }
    cout << '\n' << rightCnt;
    for(int i = name.size() - 1; i >= 0; i--) {
        if(name[i] != 'A') {
            break;
        }
        rightCnt--;
    }
    
    for(int i = name.size() - 1; i >= 0; i--) {
        int updown = name[i] - 'A';
        if(name[i] - 'A' > 13) {
            updown = 26 - updown;
        }
        leftCnt += updown;
    }
    for(int i = 1; i < name.size(); i++) {
        if(name[i] != 'A') {
            break;
        }
        leftCnt--;
    }
    
    answer = min(rightCnt, leftCnt);
    
    return answer;
}