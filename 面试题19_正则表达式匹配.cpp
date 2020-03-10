#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        if(slen== 0 && plen == 0) return true;
        if(plen == 0) return false;
        vector<vector<bool>> match(slen+1, vector<bool>(plen+1, false));
        match[0][0] = true;
        for(int j=0; j<plen; j++){
            if(p[j] == '*'){
                match[0][j+1] = match[0][j] || match[0][j-1];
            }
        }

        for(int i=0; i<slen; i++){
            for(int j=0; j<plen; j++){
                if(p[j] == '*'){
                    if(p[j-1] == '.' || p[j-1] == s[i]){
                        match[i+1][j+1] = match[i+1][j] || match[i+1][j-1] || match[i][j+1];
                    }
                    else{
                        match[i+1][j+1] = match[i+1][j-1];
                    }
                }
                else if(p[j] == '.' || p[j] == s[i]){
                    match[i+1][j+1] = match[i][j];
                }
            }
        }
        return match[slen][plen];
    }
};


