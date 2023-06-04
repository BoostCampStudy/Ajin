#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string change_n(int n, int num);
string nums = "0123456789ABCDEF";

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
        new_n += nums[num % n];
        num /= n;
    }
    reverse(new_n.begin(), new_n.end());
    return new_n;
}