#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int temp[rows][columns], board[rows][columns];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            board[i][j] = i*columns + j + 1;
        }
    }

    for(int k = 0; k < queries.size(); k++) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                temp[i][j] = 0;
            }
        }
        
        int srow = queries[k][0] - 1, scol = queries[k][1] - 1;
        int erow = queries[k][2] - 1, ecol = queries[k][3] - 1;
        
        for(int i = scol; i < ecol; i++) {   
            temp[srow][i+1] = board[srow][i];
        }
        for(int i = srow; i < erow; i++) {
            temp[i+1][ecol] = board[i][ecol];
        }
        for(int i = ecol; i > scol; i--) {
            temp[erow][i-1] = board[erow][i];
        }
        for(int i = erow; i > srow; i--) {
            temp[i-1][scol] = board[i][scol];
        }
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(temp[i][j] == 0) {
                    temp[i][j] = board[i][j];
                }
                else {
                    pq.push(temp[i][j]);
                }
            }
        }
        answer.push_back(pq.top());
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                board[i][j] = temp[i][j];
            }
        }
         while(!pq.empty()) {
            pq.pop();
        }
    }
    
    
    return answer;
}