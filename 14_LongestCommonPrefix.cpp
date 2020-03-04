#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if(num == 0) return "";
        int len = strs[0].size();
        for(int i = 0; i<len; i++){
            for(int j=1; j<num; j++){
                if(strs[j].size() <= i || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};