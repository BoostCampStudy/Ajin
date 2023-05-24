#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int t[27];
int year, month, date;
int cur_terms;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    //2022.05.19
    year = stoi(today.substr(0,4));
    month = stoi(today.substr(5,2));
    date = stoi(today.substr(8,2));
    
    for(int i = 0; i < terms.size(); i++) {
        int index = terms[i].substr(0, 1).at(0) - 'A';
        t[index] = stoi(terms[i].substr(2));
    }
    
    for(int i = 0; i < privacies.size(); i++) {
        int cterm = privacies[i].substr(11).at(0) - 'A';
        
        int cyear = stoi(privacies[i].substr(0,4));
        int cmonth = stoi(privacies[i].substr(5,2)) + t[cterm];
        int cdate = stoi(privacies[i].substr(8,2));
        
        while(cmonth > 12) {
            cyear++;
            cmonth -= 12;
        }
        cout << cyear << ' ' << cmonth << ' ' << cdate << '\n';

        int cnum = cyear * 10000 + cmonth * 100 + cdate;
        int tnum = year * 10000 + month * 100 + date;
        
        if(cnum <= tnum) {
            answer.push_back(i + 1);
        }
        
    }
    
    return answer;
}