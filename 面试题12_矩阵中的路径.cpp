#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length();
        if(len == 0) return true;
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();
        if(n == 0) return false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(subExist(board, i, j, word, 0)) return true; 
            }
        }
        return false;
    }

    bool subExist(vector<vector<char>>& board, int x, int y, string& word, int index){
        int len = word.length();
        if(len == index) return true;
        int m = board.size(), n = board[0].size();
        if(x<0 || x>=m || y<0 || y>=n || board[x][y] != word[index]) return false;
        char tmp = board[x][y];
        board[x][y] = '\n';
        bool res = subExist(board, x-1, y, word, index+1) || subExist(board, x, y-1, word, index+1)
        || subExist(board, x+1, y, word, index+1) || subExist(board, x, y+1, word, index+1);
        board[x][y] = tmp;
        return res;
    }
};

int main(){
    vector<vector<char>> m = {{'a', 'b'}};
    Solution s;
    cout << s.exist(m, "ba") <<endl;
    return 0;
}