#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int len = s.length();
        if(len == 0) return res;
        vector<string> cache;
        subPartition(s, res, cache, 0, len);
        return res;
    }

    void subPartition(string& s, vector<vector<string>>& res, vector<string>& cache, int index, int len){
        if(index == len){
            res.push_back(cache);
        }
        else{
            for(int i=index+1; i<=len; i++){
                string tmp = s.substr(index, i-index);
                if(isPalindrome(tmp)){
                    cache.push_back(tmp);
                    subPartition(s, res, cache, i, len);
                    cache.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string s){
        int i = 0, j = s.length()-1;
        while (i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};