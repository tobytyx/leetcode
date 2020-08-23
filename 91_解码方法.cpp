#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0) return 0;
        vector<int> tmp(len+1, 0);
        tmp[0] = 1;
        for(int i=1; i<=len; i++){
            if(s[i-1] != '0'){
                tmp[i] = tmp[i] + tmp[i-1];
            }
            if(i > 1){
                int buff = atoi(s.substr(i-2, 2).c_str());
                if(9 < buff && buff <= 26) tmp[i] = tmp[i] + tmp[i-2];
            }
        }
        return tmp[len];
    }
};

int main(){
    Solution s;
    int i = s.numDecodings("0");
    cout << i << endl;
    return 0;
}