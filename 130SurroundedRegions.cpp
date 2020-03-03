#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O') bfs(board, 0, j);
            if(board[m-1][j] == 'O') bfs(board, m-1, j);
        }
        for(int i=1; i<m; i++){
            if(board[i][0] == 'O') bfs(board, i, 0);
            if(board[i][n-1] == 'O') bfs(board, i, n-1);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'B') board[i][j] = 'O';
            }
        }
        return;
    }

    void bfs(vector<vector<char>>& board, int i, int j){
        deque<pair<int, int>> q(1, pair(i, j));
        int m = board.size(), n = board[0].size();
        board[i][j] = 'B';
        while(!q.empty()){
            pair<int, int> tmp = q.back();
            i = tmp.first, j = tmp.second;
            q.pop_back();
            vector<pair<int, int>> r = {
                pair(i-1, j), pair(i, j-1), pair(i+1, j), pair(i, j+1)
            };
            for(auto s: r){
                i = s.first, j = s.second;
                if(i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O'){
                    board[i][j] = 'B';
                    q.push_front(s);
                }
            }
        }
    }
};