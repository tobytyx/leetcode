#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxRec = 0;
        int m = matrix.size();
        if(m == 0) return maxRec;
        int n = matrix[0].size();
        if(n == 0) return maxRec;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> stack;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j] = matrix[i][j] == '1' ? dp[i][j] + 1 : 0;
                while(!stack.empty() && dp[i+1][stack.back()] > dp[i+1][j]){
                    int index = stack.back();
                    stack.pop_back();
                    int weight = stack.empty() ? j : j - stack.back() - 1;
                    maxRec = max(maxRec, weight * dp[i+1][index]);
                }
                stack.push_back(j);
            }
            while(!stack.empty() && dp[i+1][stack.back()] > dp[i+1][n]){
                int index = stack.back();
                stack.pop_back();
                int weight = stack.empty() ? n : n - stack.back() - 1;
                maxRec = max(maxRec, weight * dp[i+1][index]);
            }
            stack.clear();
        }
        return maxRec;
    }
};

int main(){
    
    return 0;
}