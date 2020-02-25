#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        while(!s.empty() && s.back() == ' ') s.pop_back();
        if(s.empty()) return 0;
        size_t last_space = s.find_last_of(' ');
        if(last_space == string::npos) return s.length();
        return s.length() - 1 - last_space;
    }
};
