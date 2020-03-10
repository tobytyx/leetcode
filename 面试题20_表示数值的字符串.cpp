#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        while(!s.empty() && s.back() == ' ') s.pop_back();
        int len = s.length();
        if(len == 0) return false;
        int i = 0;
        bool pre = true, deci = false, inter = false, exp=false;
        // A
        while(i < len){
            if(s[i] == ' '){
                if(!pre) 
                    return false;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(!pre) return false;
                pre = false;
            }
            else if('0' <= s[i] && s[i] <= '9'){
                inter = true;
                pre = false;
            }
            else if(s[i] == '.'){
                deci = true;
                i++;
                break;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(!inter) return false;
                exp = true;
                i++;
                break;
            }
            else return false;
            i++;
        }
        
        if(i == len){
            if(inter && !exp) return true;
            return false;
        }
        // B
        if(deci){
            while(i < len){
                if('0' <= s[i] && s[i] <= '9'){
                    i++;
                    inter = true;
                }
                else if(s[i] == 'e' || s[i] == 'E'){
                    if(inter == false) return false;
                    exp = true;
                    i++;
                    break;
                }
                else return false;
            }
        }
        
        if(i == len){
            if(!exp) return true;
            return false;
        }
        // C
        pre = true, inter = false;
        while(i < len){
            if(s[i] == '+' || s[i] == '-'){
                if(!pre) return false;
                pre = false;
            }
            else if('0' <= s[i] && s[i] <= '9'){
                pre = false;
                inter = true;
            }
            else return false;
            i++;
        }
        if(inter) return true;
        return false;
    }
};

int main(){
    string strs[5] = {"+100", "5e2", "e5", ".e5", "1.e5"};
    Solution s;
    for(string str: strs){
        printf("%d\n", s.isNumber(str));
    }
    return 0;
}