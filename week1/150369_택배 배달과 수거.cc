#include <iostream>
#include <string>
#include <vector>

using namespace std;

int indexD, indexP;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    indexD = indexP = n - 1;
    
    while(indexP >= 0 && indexD >= 0) {
        answer += 2 * (max(indexD, indexP) + 1 );
        //cout << answer << '\n';
        
        int c = 0;
        while(indexD >= 0 && c <= cap) {
            if(deliveries[indexD] <= cap - c) {
                c += deliveries[indexD];
            }
            else {
                deliveries[indexD] -= cap - c;
                break;
            }
            indexD--;
        }
        
        c = 0;
        while(indexP >= 0 && c <= cap) {
            if(pickups[indexP] <= cap - c) {
                c += pickups[indexP];
            }
            else {
                pickups[indexP] -= cap - c;
                break;
            }
            indexP--;
        }

    }
    
    
    return answer;
}