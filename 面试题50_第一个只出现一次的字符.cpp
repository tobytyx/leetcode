#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> map(256, -1);
        int len = s.length();
        if(len == 0) return ' ';
        for(int i=0; i<len; i++){
            if(map[s[i]] == -1) map[s[i]] = i;
            else map[s[i]] = -2;
        }
        int min_index = len;
        char min_char = ' ';
        for(int i=0; i<256; i++){
            if(map[i] >= 0 && map[i] < min_index){
                min_index = map[i];
                min_char = i;
            }
        }
        return min_char;
    }
};