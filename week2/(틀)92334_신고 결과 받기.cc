#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<string, int> id_map;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    vector<int> counts(id_list.size());
    vector<string> reporter, reported;

    for(int i = 0; i < report.size(); i++) {
        stringstream str(report[i]);
        string buffer;
        
        bool isfirst = true;
        while (getline(str, buffer, ' ')) {
            if(isfirst) {
                reporter.push_back(buffer);
            }
            else {
                reported.push_back(buffer);
            }
            isfirst = false;
        }
        for(int j = 0; j < id_list.size(); j++) {
            if(reported.back() == id_list[j]) {
                id_map[reporter[i]]++;
                cout << reporter[i] << ' ' << id_map[reporter[i]] << '\n';
            }
        }
    }
    
    for(int i = 0; i < reported.size(); i++) {
        for(int j = 0; j < id_list.size(); j++) {
            if(reported[i] == id_list[j]) {
                counts[j]++;
                break;
            }
        }
    }
    
    return answer;
}