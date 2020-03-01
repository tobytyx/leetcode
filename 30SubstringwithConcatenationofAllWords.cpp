#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int s_len = s.length(), w_len = words.size();
        if(s_len == 0 || w_len == 0) return res;
        int wl = words[0].length();
        unordered_map<string, int> m;
        for(string s: words){
            m[s]++;
        }
        for(int i=0; i<wl; i++){
            unordered_map<string, int> buff;
            int count = 0;
            int left = i;
            for(int j=i; j<=s_len-wl; j+=wl){
                string j_str = s.substr(j, wl);
                if(m.find(j_str) != m.end()){
                    buff[j_str]++;
                    count++;
                }
                else{
                    left = j + wl;
                    count = 0;
                    buff.clear();
                    continue;
                }
                while(buff[j_str] > m[j_str]){
                    string c_str = s.substr(left, wl);
                    left += wl;
                    buff[c_str]--;
                    count--;
                }
                if(count == words.size()){
                    res.push_back(left);
                    string c_str = s.substr(left, wl);
                    left += wl;
                    buff[c_str]--;
                    count--;
                }
            }
        }
        return res;
    }
};