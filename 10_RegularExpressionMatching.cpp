#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> match(slen+1, vector<bool>(plen+1, false));
        match[0][0] = true;
        for(int j=0; j<plen; j++){
            if(p[j] == '*' && match[0][j-1]) match[0][j+1] = true;
        }
        for(int i=0; i<slen; i++){
            for(int j=0; j<plen; j++){
                if(p[j] == '*'){
                    if(p[j-1] == s[i] || p[j-1] == '.'){
                        match[i+1][j+1] = match[i][j+1] || match[i+1][j] || match[i+1][j-1];
                    }
                    else{
                        match[i+1][j+1] = match[i+1][j-1];
                    }
                }
                else{
                    match[i+1][j+1] = match[i][j] && (p[j] == '.' || p[j] == s[i]);
                }
            }
        }
        return match[slen][plen];
    }
};


class Solution2 {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> match(slen+1, vector<bool>(plen+1, false));
        match[0][0] = true;
        for(int j=0; j<plen; j++){
            match[0][j+1] = (p[j] == '*' && match[0][j-1]);
        }
        for(int i=0; i<slen; i++){
            for(int j=0; j<plen; j++){
                if(s[i] == p[j] || p[j] == '.'){
                    match[i+1][j+1] = match[i][j];
                }
                else if(p[j] == '*'){
                    if(j > 0 && (p[j-1] == '.' || p[j-1] == s[i]))
                        match[i+1][j+1] = match[i][j+1] || match[i+1][j] || match[i+1][j-1];
                    else{
                        match[i+1][j+1] = match[i+1][j-1];
                    }
                }
            }
        }
        return match[slen][plen];
    }
};


int main(){
    Solution2 s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("", ".*") << endl;

    return 0;
}
