#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len == 0) return true;
        if(len % 2 == 1) return false;
        vector<char> stack;
        for(int i=0; i<len; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') stack.push_back(s[i]);
            else{
                if(stack.empty()) return false;
                char top = stack.back();
                if((top == '(' and s[i] == ')') ||
                (top == '[' and s[i] == ']') ||
                (top == '{' and s[i] == '}')){
                    stack.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        if(stack.empty()) return true;
        return false;
    }
};