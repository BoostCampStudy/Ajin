#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<float, int> &a, pair<float, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> failure; //실패율, 스테이지
    
    int reach = 0;
    int p = stages.size();
    
    for (int i=1; i<=N; i++) {
        int fail = count(stages.begin(), stages.end(), i);
        
        if (stages.size() == reach) {
            failure.push_back({0, i});
            continue;
        }

        float curfail = (float)fail / (float)(p - reach);
        failure.push_back({curfail, i});
        reach += fail;
    }
    
    sort(failure.begin(), failure.end(), cmp);
    
    for (int i=0; i<failure.size(); i++) {
        answer.push_back(failure[i].second);
    }
    
    return answer;
}