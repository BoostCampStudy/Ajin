#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    //1. 세로로 queue에 넣기
    vector<queue<int>> col(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j]) {
                col[j].push(board[i][j]);
            }
        }
    }
    
    //2. moves 돌면서 바구니에 채우기
    vector<int> basket;
    for(int i = 0; i < moves.size(); i++) {
        int idx = moves[i] - 1;
        if(!col[idx].empty()) {
            int pick = col[idx].front();
            basket.push_back(pick);
            col[idx].pop();
        }
    }
    
    //3. 터트리기
    int basket_size = basket.size();
    while(1) {
        bool check = false;
        
        for(int i = 0; i < basket_size - 1; i++) {
            if(basket[i] == basket[i+1]) {
                basket.erase(basket.begin() + i);
                basket.erase(basket.begin() + i);
                basket_size -= 2;
                answer += 2;
                check = atrue;
            }
        }

        if(check == false) {
            break;
        }
    }
    return answer;
}