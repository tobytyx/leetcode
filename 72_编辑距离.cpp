#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        if(len1 == 0 && len2 == 0)  return 0;
        if(len1 == 0) return len2;
        if(len2 == 0) return len1;
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        dp[0][0] = 0;
        for(int i=1; i<=len2; i++) dp[0][i] = i;
        for(int i=1; i<=len1; i++) dp[i][0] = i;
        for(int i=0; i<len1; i++){
            for(int j=0; j<len2; j++){
                int min_change = word1[i] == word2[j] ? dp[i][j]: dp[i][j]+1;
                min_change = min(min_change, dp[i+1][j]+1);
                min_change = min(min_change, dp[i][j+1]+1);
                dp[i+1][j+1] = min_change;
            }
        }
        return dp[len1][len2];
    }
};