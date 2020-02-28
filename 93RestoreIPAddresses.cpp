#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> res;
        for(int i=1; i<4 && i<len-2; i++){
            for(int j=1; j<4&&j<len-i-1; j++){
                for(int k=1; k<4&&k<len-i-j; k++){
                    string l1=s.substr(0, i), l2=s.substr(i, j);
                    string l3=s.substr(i+j, k), l4=s.substr(i+j+k);
                    if(isValid(l1) && isValid(l2) && isValid(l3) && isValid(l4))
                        res.push_back(l1 + "." + l2 + "." + l3 + "." + l4);
                }
            }
        }
        return res;
    }

    bool isValid(string s){
        int len = s.length();
        if(len==0 || len>3 || (s[0] == '0' && len > 1) || stoi(s) > 255){
            return false;
        }
        return true;
    }
};