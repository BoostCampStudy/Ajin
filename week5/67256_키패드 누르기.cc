#include <string>
#include <vector>
#include <cmath>

using namespace std;

int lrow = 3, lcol = 0;
int rrow = 3, rcol = 2;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int i = 0; i < numbers.size(); i++) {
        int crow, ccol;
        if(numbers[i] == 0) {
            crow = 3; ccol = 1;
        }
        else {
            crow = (numbers[i] - 1) / 3;
            ccol = (numbers[i] - 1) % 3;
        }
        
        if(ccol == 0) { // 1,4,7
            answer.push_back('L');
            lrow = crow; lcol = ccol;
        }
        else if(ccol == 2) { //3,6,9
            answer.push_back('R');
            rrow = crow; rcol = ccol;
        }
        else { //2,5,8,0
            int ldis = abs(crow - lrow) + abs(ccol - lcol);
            int rdis = abs(crow - rrow) + abs(ccol - rcol);
            
            if(ldis < rdis) { //왼손 더 짧음
                answer.push_back('L');
                lrow = crow; lcol = ccol;
            }
            else if(rdis < ldis) { //오른손 더 짧아
                answer.push_back('R');
                rrow = crow; rcol = ccol;
            }
            else { //양손 거리 같음
                if(!hand.compare("left")) { //왼손잡이
                    answer.push_back('L');
                    lrow = crow; lcol = ccol;
                }
                else { //오른손잡이
                    answer.push_back('R');
                    rrow = crow; rcol = ccol;
                }
            }
        }
    }
    
    return answer;
}