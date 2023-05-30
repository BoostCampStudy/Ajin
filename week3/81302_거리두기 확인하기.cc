#include <string>
#include <vector>
#include<cstring>
#include <iostream>
using namespace std;

bool flag;
bool visited[5][5];
int dir[4][2] = {{-1,0}, {0,1}, {1, 0}, {0, -1}};

void DFS(vector<vector<string>> places, int n, int i, int j, int depth) {
    visited[i][j] = true;
    depth++;
    
    for(int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];

        if(x < 0 || y < 0 || x >= 5 || y >= 5) {
            continue;
        }
        
        if(places[n][x][y] == 'X') {
            continue;
        }
        
        if(visited[x][y] == true) {
            continue;
        }
        
        if(places[n][x][y] == 'P') {
            flag = false;
        }
        
        if(places[n][x][y] == 'O' && depth < 2) {
            DFS(places, n, x, y, depth);
        }
    }
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++) {
        bool check = false;
        memset(visited,false,sizeof(visited));
        flag = true;
        
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(visited[j][k] == false && places[i][j][k] == 'P') {
                    DFS(places, i, j, k, 0);
                    if(flag == false) {
                        check = true;
                        break;
                    }
                }
            }
        }

        if(check == true) {
            answer.push_back(0);
        }
        else {
            answer.push_back(1);
        }
    }

    return answer;
}