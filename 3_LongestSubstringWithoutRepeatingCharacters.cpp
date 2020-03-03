#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len < 2) return len;
        int low = 0, max_len = 1;
        int map[128] = {0};
        map[s[0]] = 1;
        for(int i=1; i<len; i++){
            map[s[i]]++;
            if(map[s[i]] <= 1){
                max_len = i-low+1 > max_len ? i-low+1 : max_len; 
            }
            else{
                while(map[s[i]] > 1){
                    map[s[low]]--;
                    low++;
                }
            }
        }
        return max_len;
    }
};

int main(){
    string st;
    cin >> st;
    Solution s;
    printf("%d\n", s.lengthOfLongestSubstring(st));
    return 0;
}
