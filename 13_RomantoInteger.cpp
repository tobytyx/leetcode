#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length(), res = 0;
        if(len == 0) return 0;
        unordered_map<string, int> map = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50},
            {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        };
        int i = 0;
        while(i < len){
            if(i < len - 1){
                string subs = s.substr(i, 2);
                if(map.find(subs) != map.end()){
                    res += map[subs];
                    i += 2;
                }
                else{
                    subs.pop_back();
                    res += map[subs];
                    i += 1;
                }
            }
            else{
                string subs = s.substr(i, 1);
                res += map[subs];
                i += 1;
            }
        }
        return res;
    }
};