#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> check(m, vector<bool>(n, false));
    bool flag = false;
    while(1) {
        for(int i = 0; i < check.size(); i++) {
            fill(check[i].begin(), check[i].end(), false);
        }
        flag = false;
        
        //1. 4개 블럭 묶기
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(board[i][j] == '0') {
                    continue;
                }
                char a = board[i][j]; char b = board[i][j+1];
                char c = board[i+1][j]; char d = board[i+1][j+1];
                if(a == b && b == c && c == d) {
                    check[i][j] = true; check[i][j+1] = true;
                    check[i+1][j] = true; check[i+1][j+1] = true;
                    flag = true;
                }
            }
        }

        //2. 터진 거 매꾸기
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(check[i][j]) {
                    board[i][j] = '0';
                    answer++;
                }
            }
        }

        //3. 빈공간 채우기
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
               if(board[i][j] == '0') {
                   for(int k =i; k > 0; k--) {
                       if(board[k-1][j] == '0') {
                           break;
                       }
                       board[k][j] = board[k-1][j];
                       board[k-1][j] = '0';
                   }
               }
            }

        }

        /*
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << temp[j][i] <<' ';
            }
            cout << '\n';
        }
        */
        if(flag == false) {
            break;
        }
        
    }
    
    
    return answer;
}