#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
 
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
 
        for (int j = 0; j < city.length(); j++) {
            city[j] = tolower(city[j]);
        }
 
        bool check = false;
        int idx = 0;

        for (; idx < cache.size(); idx++) {
            if (cache[idx] == city) {
                check = true;

                cache.push_back(city);
                cache.erase(cache.begin() + idx);
                answer += 1;

                break;
            }
        }

        if(!check) {
            cache.push_back(city);
            if (cache.size() > cacheSize) {
                cache.pop_front();
            }
            answer += 5;
        }
    }  
    return answer;
}