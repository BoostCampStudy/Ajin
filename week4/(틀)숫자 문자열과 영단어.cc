#include <iostream>
#include <string>
#include <vector>

using namespace std;

string snum[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i]  >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            answer = answer * 10 + num;
        }
        else {
            for (int j = 0; j < 10; j++) {
                int N = snum[j].length();
                if(!snum[j].compare(0, N, s, i, N)) {
                    answer = answer * 10 + j;
                }
            }
        }
    }  

    return answer;
}