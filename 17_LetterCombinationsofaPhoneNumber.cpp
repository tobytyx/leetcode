#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0) return res;
        string cache;
        unordered_map<int, vector<char>> map;
        map[2] = {'a', 'b', 'c'};
        map[3] = {'d', 'e', 'f'};
        map[4] = {'g', 'h', 'i'};
        map[5] = {'j', 'k', 'l'};
        map[6] = {'m', 'n', 'o'};
        map[7] = {'p', 'q', 'r', 's'};
        map[8] = {'t', 'u', 'v'};
        map[9] = {'w', 'x', 'y', 'z'};
        combin(res, cache, map, digits, 0);
        return res;
    }

    void combin(vector<string>& res, string& cache, unordered_map<int, vector<char>>& map, string& digits, int index){
        if(index >= digits.length()){
            res.push_back(cache);
            return;
        }
        vector<char> chars = map[digits[index]-'0'];
        int len = chars.size();
        for(int i=0; i<len; i++){
            cache.push_back(chars[i]);
            combin(res, cache, map, digits, index+1);
            cache.pop_back();
        }
    }
};

