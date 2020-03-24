#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int len = s.length();
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=len; i++){
            dp[i] = dp[i-1];
            if(valid(s[i-2], s[i-1])) dp[i] += dp[i-2];
        }
        return dp[len];
    }

    bool valid(char& a, char& b){
        if(a-'0' > 2 || a == '0' || (a == '2' && b > '5')) return false;
        return true;
    }
};