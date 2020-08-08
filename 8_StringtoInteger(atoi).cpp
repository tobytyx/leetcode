#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int symbol = 1, res = 0;
        int i = 0, len = str.length();
        if(len == 0) return 0;
        while(i < len && str[i] == ' ') i++;
        if(i == len) return res;
        if(str[i] == '+'){
            i++;
        }
        else if(str[i] == '-'){
            i++;
            symbol = -1;
        }
        while(i < len){
            if(str[i] < '0' || str[i] > '9'){
                return res * symbol;
            }
            int integer = str[i] - '0';
            if((INT_MAX-integer) / 10 <= res - 0.1){
                if(symbol == 1) return INT_MAX;
                return INT_MIN;
            }
            res = res * 10 + integer;
            i++;
        }
        return symbol *  res;
    }
};
