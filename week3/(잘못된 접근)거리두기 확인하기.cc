#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{-1,0}, {0,1}, {1, 0}, {0, -1}};
int dash[4][2] = {{-1,-1}, {-1,1},{1,1},{1,-1}};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int n = 0;
    while(n < 5) {
        //사람 위치 저장하기
        vector<pair<int,int>> point;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(places[n][i][j] == 'P') {
                    point.push_back(make_pair(i,j));
                }
            }
        }
        
        bool check = false;
        for(int i = 0; i < point.size(); i++) {
            int cnt = 0;
            int r = point[i].first;
            int c = point[i].second;
            
            //상하좌우에 사람?
            for(int j = 0; j < 4; j++) {
                int rr = r + dir[j][0];
                int cc = c + dir[j][1];
                
                if(rr < 0 || cc < 0 || rr > 4 || cc > 4) {
                    continue;
                }
                if(places[n][rr][cc] == 'P') {
                    check = true;
                    break;
                }
            }
            
            //대각선에 사람?
            for(int j = 0; j < 4; j++) {
                int rr = r + dash[j][0];
                int cc = c + dash[j][1];
                
                if(rr < 0 || cc < 0 || rr > 4 || cc > 4) {
                    continue;
                }
                
                if(places[n][rr][cc] == 'P') {
                    if(places[n][r][cc] != 'X' || places[n][rr][c] != 'X') {
                        check = true;
                        break;
                    }
                }
            }
            
            //2칸 상하좌우에 사람?
            for(int j = 0; j < 4; j++) {
                int rr = r + dir[j][0] * 2;
                int cc = c + dir[j][1] * 2;
                
                if(rr < 0 || cc < 0 || rr > 4 || cc > 4) {
                    continue;
                }
                if(places[n][rr][cc] == 'P') {
                    check = true;
                    break;
                }
            }
        }
        if(!check) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
        n++;
    }

    return answer;
}