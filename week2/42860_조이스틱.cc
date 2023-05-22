#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int slideMove = name.size() - 1;

    for(int i = 0; i < name.size(); i++) {
        //위&아래
        if(name[i] - 'A' < 14) {
            answer += name[i] - 'A';
        }
        else {
            answer += 'Z' - name[i] + 1;
        }
        
        //오른쪽&왼쪽
        int idx = i + 1;
        while(idx < name.size() && name[idx] == 'A') {
            idx++;
        }
        int gap = name.size() - idx;
        slideMove = min(slideMove, i + gap + min(i, gap));
    }
    answer += slideMove;
    
    return answer;
}