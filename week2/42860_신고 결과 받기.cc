#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    vector<int> counts(id_list.size());
    map<string, int> id_idx_map;
    map<string, set<string>> report_map;
    
    for (auto i=0; i<id_list.size(); ++i){
        id_idx_map[id_list[i]] = i;
    }

    for(int i = 0; i < report.size(); i++) {
        stringstream str(report[i]);
        string reporter, reported;
        
        str >> reporter >> reported;
        report_map[reported].insert(reporter);

    }
    for(auto it = report_map.begin(); it != report_map.end(); it++) {
        cout << *it << 'n';
    }
    for(int i = 0; i < report_map.size(); i++) {
        if(report_map.second.size() >= k) {
            for(auto iter : report_map[i].second) {
                answer[id_idx_map[iter]]++;
            }
        }
    }
    

    return answer;
}