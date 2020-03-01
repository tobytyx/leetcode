#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        vector<bool> cache(s_len+1, false); // cache[j]表示p[0:i] 能否匹配s[0:j]
        cache[0] = true;
        for(int i=0; i<p_len; i++){
            bool pre = cache[0]; 
            cache[0] = cache[0] && (p[i] == '*'); // p[0:i]能否匹配空串
            for(int j=1; j<=s_len; j++){
                bool tmp = cache[j];
                if(p[i] == '*'){
                    // cache[j-1]: 当前p串能否匹配s[j-1], cache[j]: 不包含当前字符的p能否匹配s[j]
                    cache[j] = cache[j-1] || cache[j];
                }
                else{
                    // pre: p[0:i] - s[0:j]
                    cache[j] = pre && (p[i] == s[j-1] || p[i] == '?');
                }
                pre = tmp;
            }
        }
        return cache[s_len];
    }
};