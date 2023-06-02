#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m, m1, m2;
    for(int i = 0; i < str1.size() - 1; i++) {
        string element ="";
        if(isalpha(str1[i]) && isalpha(str1[i+1])) {
            element += tolower(str1[i]);
            element += tolower(str1[i+1]);
            m[element]++;
            m1[element]++;
        }
    }
    for(int i = 0; i < str2.size() - 1; i++) {
        string element ="";
        if(isalpha(str2[i]) && isalpha(str2[i+1])) {
            element += tolower(str2[i]);
            element += tolower(str2[i+1]);
            m[element]++;
            m2[element]++;
        }
    }
    
    int uni = 0; //합집합
    int inter = 0; //교집합
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        //cout << iter->first << ' ' << iter->second << '\n';
        if(m1.find(iter->first) != m1.end() && m2.find(iter->first) != m2.end()) {
            //cout << iter->first << '\n';
            //cout << m1[iter->first] << ' ' << m2[iter->first] << '\n';
            inter +=  min(m1[iter->first], m2[iter->first]);
            continue;
        }
    }
    
    for(auto iter = m1.begin(); iter != m1.end(); iter++) {
        uni += iter->second;
    }
    for(auto iter = m2.begin(); iter != m2.end(); iter++) {
        uni += iter->second;
    }
    uni -= inter;
    
    //cout << inter << ' ' << uni <<'\n';
    
    float similarity;
    if(inter == 0 && uni == 0) {
        similarity = 1;
    }
    else if(uni == 0) {
        similarity = float(inter);
    }
    else {
        similarity = float(inter) / float(uni);
    }
    
    answer = similarity * 65536;

    return answer;
}