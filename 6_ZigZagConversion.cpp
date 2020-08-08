#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        vector<string> strs(numRows, string());
        int step = 1, row = 0;
        for(char c: s){
            strs[row].push_back(c);
            row += step;
            if(row == numRows - 1) step = -1;
            if(row == 0) step = 1;
        }
        for(int i=1; i<numRows; i++){
            strs[0].append(strs[i]);
        }
        return strs[0];
    }
};


class Solution2 {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        vector<string> strs(numRows, string());
        int step = 1, row=0;
        for (char c: s){
            strs[row].push_back(c);
            row += step;
            if (row == 0 || row == numRows-1) step = -step;
        }
        for(int i=1; i<numRows; i++)
            strs[0].append(strs[i]);
        return strs[0];
    }
};
