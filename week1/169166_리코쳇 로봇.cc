#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void move_robot(vector<string> &board, int r, int c);

int start[2], finish[2], answer, rowSize, colSize;
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
bool visited[101][101];
vector<vector<int>> cnt;

int solution(vector<string> board) {
    rowSize = board.size();
    colSize = board[0].size();
    cnt.resize(rowSize, vector<int>(colSize, 0xffffff));

    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < colSize; j++) {
            if(board[i][j] == 'G') {
                finish[0] = i;
                finish[1] = j;
            }
            else if(board[i][j] == 'R') {
                start[0] = i;
                start[1] = j;
            }
        }
    }

    move_robot(board, start[0], start[1]);
    
    return answer;
}

void move_robot(vector<string> &board, int r, int c) {
    queue<pair<int,int> > queue;
    queue.push(make_pair(r,c));
    visited[r][c] = true;
    cnt[r][c] = 0;

    while(!queue.empty()) {
        int curRow = queue.front().first;
        int curCol = queue.front().second;
        queue.pop();

        for(int i = 0; i < 4; i++) {
            int nextRow = curRow;
            int nextCol = curCol;

            while(1) {
                nextRow += dir[i][0];
                nextCol += dir[i][1];
                
                if(nextRow < 0 || nextRow >= rowSize) {
                    nextRow -= dir[i][0];
                    nextCol -= dir[i][1];
                    break;
                }
                if(nextCol < 0 || nextCol >= colSize) {
                    nextRow -= dir[i][0];
                    nextCol -= dir[i][1];
                    break;
                }
                if(board[nextRow][nextCol] == 'D') {
                    nextRow -= dir[i][0];
                    nextCol -= dir[i][1];
                    break;
                }
            }
            if(visited[nextRow][nextCol]) {
                continue;
            }
            visited[nextRow][nextCol] = true;
            cnt[nextRow][nextCol] = min(cnt[nextRow][nextCol], cnt[curRow][curCol] + 1);
            //cout << nextRow << ',' << nextCol << ' ' << cnt[nextRow][nextCol] << '\n';
            queue.push(make_pair(nextRow, nextCol));
        }
    }
    
    if(cnt[finish[0]][finish[1]] == 0xffffff) {
        answer = -1;
    }
    else {
        answer = cnt[finish[0]][finish[1]];
    }
    
}