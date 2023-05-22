#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
vector <string> musicinfo;
vector <int> runTimes, musicTimes;
vector <string> musicNames, musics, runMusics;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    //파싱하기..
    for(int i = 0; i < musicinfos.size(); i++) {
        stringstream sstream(musicinfos[i]);
        string word;

        while(getline(sstream, word, ',')) {
            musicinfo.push_back(word);
        }
        int startTime = stoi(musicinfo[0].substr(0,2)) * 60 + stoi(musicinfo[0].substr(3,2));
        int finishTime = stoi(musicinfo[1].substr(0,2)) * 60 + stoi(musicinfo[1].substr(3,2));
        runTimes.push_back(finishTime - startTime);       
        musicNames.push_back(musicinfo[2]);        
        musics.push_back(musicinfo[3]);
        
        //음악 시간 구하기
        int musicTime = 0;
        for(int j = 0; j < musics[i].size(); j++) {
            if(musics[i][j] == '#') {
                continue;
            }
            musicTime++;
        }
        musicTimes.push_back(musicTime);
        
        musicinfo.clear(); 
    }
    runMusics.resize(musicinfos.size());
    
    //음악 늘리기
    for(int i = 0; i < musicinfos.size(); i++) {
        int times = runTimes[i] / musicTimes[i];
        
        if(times > 0) {
            while(times--) {
               runMusics[i].append(musics[i]);
            }
        }
        int rest = runTimes[i] % musicTimes[i];
        int idx = 0;
        for(int j = 0; j < rest; j++) {
            runMusics[i].push_back(musics[i][idx]);
            idx++;
            if(musics[i][idx+1] == '#') {
                runMusics[i].push_back(musics[i][idx]);
                idx++;
            }
        }
    }
    
    //비교하기
    vector<int> correct;
    for(int i = 0; i < musicinfos.size(); i++) {
        if(runMusics[i].find(m) != string::npos) {
            correct.push_back(i);
            //cout << runMusics[i].find(m) + m.size() <<' ';
        }
    }
    for(int i = 0; i < runMusics.size(); i++) {
        if(runMusics[i][runMusics[i].find(m) + m.size()] == '#') {
            correct.erase(correct.begin() + i);
        }
    }
    
    
    //예외처리
    if(correct.size() == 0) {
        answer += "(None)";
    }
    else {
        int maxTime = runTimes[correct[0]];
        int maxIndex = 0;
        //cout << maxTime << ' ' << maxIndex << '\n';
        for(int i = 0; i < correct.size(); i++) {
            if(runTimes[correct[i]] > maxTime) {
                maxTime = runTimes[correct[i]];
                maxIndex = correct[i];
                cout << maxTime << ' ' << maxIndex << '\n';
            }
        }
        answer += musicNames[maxIndex];
    }
    
    return answer;
}