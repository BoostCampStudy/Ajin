#include <algorithm>
using namespace std;

int gcd(int a, int b);

long long solution(int w,int h) {
    long long answer = 0;
    
    long long dash = w + h - gcd(w,h);
    answer = (long long)w * (long long)h - dash;
    return answer;
}

int gcd(int a, int b) {
    int num = 1;
    int minNum = min(a, b);
    
    for(int i = 1; i <= minNum; i++){
        if(a % i == 0 && b % i == 0) {
            num = i;
        }
    }
    
    return num;
}