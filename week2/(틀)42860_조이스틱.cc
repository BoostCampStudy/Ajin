#include <iostream>
#include <string>
#include <vector>
#define ALPHABET 26

using namespace std;
void move_joystick(string name, int depth, int point);
int n, cnt, answer = 0xffffff;

int solution(string name) {
    n = name.size();
    
    move_joystick(name, 0, 0);
    return answer;
}

void move_joystick(string name, int depth, int point) {
    char cur = 'A';
    int curCnt = 0;
    for(int i = 0; i < ALPHABET; i++) {
        if(cur == name[depth]) {
            break;
        }
        cur = char(cur + 1);
        curCnt++;
    }
    if(curCnt > 13) {
        curCnt = ALPHABET - curCnt;
    }
    //cout << "curCnt: " << curCnt << '\n';
    cnt += curCnt;
    
    int goUp = (point + 1) % n;
    int goDown;
    if(point == 0) {
        goDown = n - 1;
    }
    else {
        goDown = (point - 1);
    }
    
    if(depth == n - 1) {
        answer = min(answer, cnt);
        return;
    }
    
    cnt++;
    //cout << "depth: " << depth<< " point:" << point << " cnt: " << cnt << '\n';
    //cout << "next: " << goUp << ' ' << goDown << '\n';
    move_joystick(name, depth + 1, goUp);
    move_joystick(name, depth + 1, goDown);
    cnt--;
}