#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<vector<string>> cache(n+1, vector<string>());
        cache[0].push_back("");
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                for(string s1: cache[j]){
                    for(string s2: cache[i-j-1]){
                        cache[i].push_back("("+s1+")"+s2);
                    }
                }
            }
        }
        return cache[n];
    }
};