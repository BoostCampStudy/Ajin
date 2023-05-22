#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> playtime;
vector<string> musicinfo, names, melody, melody_clone, playmusic;
string music;
map<string, int> correct;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int n = musicinfos.size();
    
    //1. 파싱하기
    for(int i = 0; i < n; i++) {
        stringstream str(musicinfos[i]);
        string word;
        
        while(getline(str, word, ',')) {
            musicinfo.push_back(word);
        }
        
        //playtime 구하기
        int start = stoi(musicinfo[0].substr(0,2)) * 60 + stoi(musicinfo[0].substr(3,2));
        int finish = stoi(musicinfo[1].substr(0,2)) * 60 + stoi(musicinfo[1].substr(3,2));
        playtime.push_back(finish - start);
        
        //names, melody 구하기
        names.push_back(musicinfo[2]);
        melody.push_back(musicinfo[3]);
        
        musicinfo.clear();
    }
    
    //2. m 반올림 처리하기 -> music
    for(int i = 0; i < m.size(); i++) {
        if(m[i] == '#') {
            char pre = music.back();
            music.pop_back();
            music.push_back(tolower(pre));
        }
        else {
            music.push_back(m[i]);
        }
        
    }
    //2. melody 반올림 처리하기 -> melody_clone
    melody_clone.resize(melody.size());
    for(int i = 0; i < melody.size(); i++) {
        for(int j = 0; j < melody[i].size(); j++) {
            if(melody[i][j] == '#') {
                char pre = melody_clone[i].back();
                melody_clone[i].pop_back();
                melody_clone[i].push_back(tolower(pre));
            }
            else {
                melody_clone[i].push_back(melody[i][j]);
            }
        }
        
    }
    
    //3. melody 늘리기 -> playmusic
    playmusic.resize(n);
    for(int i = 0; i < n; i++) {
        int times = playtime[i] / melody_clone[i].size();
        
        if(times > 0) {
            while(times--) {
                playmusic[i].append(melody_clone[i]);
            }
        }
        int rest = playtime[i] % melody_clone[i].size();
        for(int j = 0; j < rest; j++) {
            playmusic[i].push_back(melody_clone[i][j]);
        }
    }
    
    //4. 그곡내곡 찾기
    for(int i = 0; i < n; i++) {
        if(playmusic[i].find(music) != string::npos) {
            correct[names[i]] = playtime[i];
        }
    }
    
    for(auto const &pair: correct) {
        //cout << pair.first << ", " << pair.second << '\n';
        answer += pair.first;
        break;
    }

    return answer;
}