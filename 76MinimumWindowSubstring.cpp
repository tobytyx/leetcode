#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(char c: t) map[c]++;
        int head=0, tail=0, pos=0, window=INT_MAX, counter=t.length();
        while(head < s.length()){
            if(map[s[head]] > 0){
                counter--;
            }
            map[s[head]]--;
            head++;
            while(counter == 0){ // 一直覆盖着t
                if(head - tail < window){
                    window = head - tail;
                    pos = tail;
                }
                if(map[s[tail]] == 0) counter++;
                map[s[tail]]++;
                tail++;
            }
        }
        return window==INT_MAX? "": s.substr(pos, window);
    }
};
