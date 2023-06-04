#include <iostream>
#include <string>
#include <vector>

using namespace std;

string change_n(int n, int num);
vector<string> nums;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "0";
    for(int i = 0; temp.size() <= t * m; i++) {
        temp += change_n(n, i);
    }
    
    p--;
    for(int i = 0; i < temp.size(); i++) {
        if(i % m == p) {
            answer += temp[i];
        }
        if(answer.length() == t) {
            break;
        }
    }
    
    return answer;
}

string change_n(int n, int num) {
    string new_n = "";
    while(num > 0) {
        int temp = num % n;
        string c;
        if(temp > 9) {
            c = (char)(temp + 'A'-10);
        }
        else {
            c = to_string(temp);
        }
        new_n.insert(0,c);
        
        num /= n;
    }
    return new_n;
}