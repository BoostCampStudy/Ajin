#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

struct file {
    string name;
    int number;
    //string tail;
    int idx;
};

bool cmp(const file& f1, const file& f2) {
    if(f1.name == f2.name) {
        if(f1.number == f2.number) {
            return f1.idx < f2.idx;
        }
        else {
            return f1.number < f2.number;
        }
    }
    return f1.name < f2.name;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int n = files.size();
    vector<file> f(n);
    for(int i = 0; i < n; i++) {
        string temp = "";
        //1. name 분리
        for(int j = 0; j < files[i].size(); j++) {
            if(isdigit(files[i][j])) {
                temp = files[i].substr(j,files[i].size() - j);
                break;
            }
            else {
                f[i].name += tolower(files[i][j]);
            }
        }
        
        //2. 숫자, tail 분리
        string numtemp="";
        for(int j = 0; j < temp.size(); j++) {
            if(isdigit(temp[j])) {
                numtemp += temp[j];
            }
            else {
                //f[i].tail = temp.substr(j,temp.size() - j);
                break;
            }
        }
        f[i].number = stoi(numtemp);
        f[i].idx = i;
    }
    
    //3. 정렬하기
    sort(f.begin(), f.end(), cmp);
    
    //4. 출력하기
    for(int i = 0; i < n; i++) {
        cout << f[i].idx << '\n';
        answer.push_back(files[f[i].idx]);
    }
    
    return answer;
}