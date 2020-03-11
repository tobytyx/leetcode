#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        int len = s.length();
        if(len == 0) return res;
        subPermutation(s, res, 0);
        return res;
    }

    void subPermutation(string& s, vector<string>& res, int index){
        int len = s.length();
        if(index >= len){
            res.push_back(s);
            return;
        }
        for(int i=index; i<len; i++){
            if(skip(s, index, i)) continue;
            swap(s[i], s[index]);
            subPermutation(s, res, index+1);
            swap(s[i], s[index]);
        }
    }

    bool skip(string& s, int begin, int end){
        for(int i=begin; i<end; i++){
            if(s[i] == s[end]) return true;
        }
        return false;
    }
};