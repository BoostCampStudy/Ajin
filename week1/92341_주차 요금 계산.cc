#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int parkList[10000], timeList[10000], feeList[10000];
vector<int> table[4];

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int basicTime = fees[0], basicFee = fees[1], perTime = fees[2], perFee = fees[3];
    
    for(int i = 0; i < records.size(); i++) {
        string curHour = records[i].substr(0,2);
        string curMin = records[i].substr(3,2);
        string carNum = records[i].substr(6,4);
        string type = records[i].substr(11, 3);
        int curTime = stoi(curHour) * 60 + stoi(curMin);
        
        if(type.compare("IN") == 0) {
            if(curTime == 0) {
                timeList[stoi(carNum)] = -1;
            }
            else {
                timeList[stoi(carNum)] = curTime;
            }

        }
        else {
            int parkTime = curTime - timeList[stoi(carNum)];
            parkList[stoi(carNum)] += parkTime;
            timeList[stoi(carNum)] = 0;
        }  
       
    }
    for(int i = 0; i < 10000; i++) {
        if(timeList[i] != 0) {
            int maxTime = 23 * 60 + 59;
            if(timeList[i] == -1) {
                parkList[i] += maxTime;
            }
            else {
                int parkTime = maxTime - timeList[i];
                parkList[i] += parkTime;
            }
        }
        if(parkList[i] != 0) {
            if(parkList[i] < basicTime) {
                answer.push_back(basicFee);
            }
            else {
                int parkFee = basicFee + ceil(float(parkList[i] - basicTime) / float(perTime)) * perFee;
                answer.push_back(parkFee);
            }
            
        }
    }
    
    return answer;
}