#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if(len < 2) return 0;
        vector<int> cache(len, 0);
        int max_len = 0;
        for(int i=1; i<len; i++){
            if(s[i] == ')' && i-1-cache[i-1] >= 0 && s[i-1-cache[i-1]] == '('){
                cache[i] = cache[i-1] + 2 + (i-2-cache[i-1] >= 0 ? cache[i-2-cache[i-1]] : 0);
                max_len = max(max_len, cache[i]);
            }
        }
        return max_len;
    }
};

int main(){
    string s1 = "()";
    Solution s;
    cout << s.longestValidParentheses(s1) << endl;
    return 0;
}