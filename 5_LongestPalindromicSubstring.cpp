#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string x = "&";
        for(char c: s) x = x + c + "&";
        int max_i = 0, max_len = 0, mx = 0, len = x.size(), cid=0;
        vector<int> p(len, 0);
        for(int i=0; i<len; i++){
            p[i] = mx > i ? min(p[2*cid-i], mx-i) : 1;
            while(i-p[i] >= 0 && x[i-p[i]] == x[i+p[i]]){
                p[i]++;
            }
            if(p[i]+i > mx){
                mx = p[i] + i;
                cid = i;
            }
            if(p[i] > max_len){
                max_len = p[i];
                max_i = i;
            }
        }
        return s.substr((max_i-max_len+1)/2, max_len-1);
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        string x = "&";
        for(char c: s)
            x = x + c + "&";
        int max_i = 0, max_len = 0, mx = 0, len = x.size(), cid = 0;
        vector<int> p(len, 0);
        for(int i=0; i<len; i++){
            p[i] = mx > i ? min(p[2*cid-i], mx-i) : 1;
            while(i-p[i] >= 0 && x[i-p[i]] == x[i+p[i]]){
                p[i]++;
            }
            if(p[i] + i > mx){
                mx = p[i] + i;
                cid = i;
            }
            if(p[i] > max_len){
                max_len = p[i];
                max_i = i;
            }
        }
        return s.substr((max_i-max_len+1)/2, max_len-1);
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("babadada") <<endl;
    return 0;
}