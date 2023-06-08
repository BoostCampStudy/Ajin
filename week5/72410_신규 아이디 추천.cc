#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    int n = new_id.size();
    //step1.
    for(int i = 0; i < new_id.size(); i++) {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = tolower(new_id[i]);
        }
    }
    
    //step2.
    string temp;
    for(int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        if((c >= 'a' && c <= 'z')|| (c >= '0' && c<= '9') || c == '-' || c == '_' || c == '.') {
            temp += c;
        }
    }
    new_id = temp;
    
    //step3.
    temp = "";
    for(int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        if(new_id[i] == '.') {
            int j = i + 1;
            while(new_id[j] == '.') {
                j++;
            }
            i = j - 1;
            temp += c;
        }
        else {
            temp += c;
        }
    }
    new_id = temp;
    
    //step4.
    if(new_id[0] == '.') {
        new_id = new_id.substr(1, new_id.size() -1);
    }
    if(new_id[new_id.size() - 1] == '.') {
        new_id = new_id.substr(0, new_id.size() -1);
    }
    
    //step5.
    if(!new_id.compare("")) {
        for(int i = 0; i < 3; i++) { //?왜
            new_id += 'a';
        }
    }
    
    //step6.
    if(new_id.size() >= 16) {
        new_id = new_id.substr(0, 15);
    }
    if(new_id[new_id.size() - 1] == '.') {
        new_id = new_id.substr(0, 14);
    }
    
    //step7.
    if(new_id.size() <= 2) {
        char last = new_id[new_id.size() - 1];
        while(1) {
            new_id += last;
            if(new_id.size() == 3) {
                break;
            }
        }
    }
    answer = new_id;
    return answer;
}