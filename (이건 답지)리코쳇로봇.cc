#include <string>
#include <vector>
#include <queue>
#define INF 100000

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(vector<string> &board, int rowCnt, int colCnt, int rRow, int rCol)
{
    vector<vector<int>> visited(rowCnt, vector<int>(colCnt));
    vector<vector<int>> depth(rowCnt, vector<int>(colCnt,INF));
    queue<pair<int,int>> q;
    
    q.push({rRow, rCol});
    visited[rRow][rCol] = 1;
    depth[rRow][rCol] = 0;
    
    while(!q.empty())
    {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = curRow;
            int nx = curCol;
            while(1)
            {
                ny += dy[i];
                nx += dx[i];
                if(ny<0 || ny>=rowCnt || nx<0 || nx>=colCnt) //범위 밖이면
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
                if(board[ny][nx]=='D')
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
            }
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            depth[ny][nx] = min(depth[ny][nx], depth[curRow][curCol]+1);
            q.push({ny, nx});
        }
    }
    
    for(int i=0;i<depth.size();i++)
    {
        for(int j=0;j<depth[i].size();j++)
        {
            if(board[i][j]=='G')
            {
                if(depth[i][j]==INF) return -1;
                return depth[i][j];
            }
        }
    }
}

int solution(vector<string> board) {
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]=='R')
            {
                return BFS(board, board.size(), board[i].size(), i, j);
            }
        }
    }

}