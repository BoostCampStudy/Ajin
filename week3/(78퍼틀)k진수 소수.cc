#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

long long primeNum[1000001];

int solution(int n, int k) {
    int answer = 0;
    
    //1. k진수로 바꾸기
    string knum = "";
    while(n) {
        knum.insert(0, to_string(n % k));
        n /= k;
    }
    
    //2. 0으로 파싱하기
    stringstream str(knum);
    string prime;
    vector<long long> primes;
    
    while(getline(str, prime, '0')) {
        if(prime.compare("\0")) {
            primes.push_back(stoll(prime));
        }
    }
    
    //3. 소수찾기
    for(int i = 2; i <= n; i++) {
        primeNum[i] = i;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(!primeNum[i]) {
            continue;
        }
        for(int j = i*i; j <= n; j += i) {
            primeNum[j] = 0;
        }
    }
    
    //4. 소수 개수 찾기
    for(int i = 0; i < primes.size(); i++) {
        if(!primeNum[primes[i]] && primes[i] != 1) {
            answer++;
        }
    }
    
    return answer;
}