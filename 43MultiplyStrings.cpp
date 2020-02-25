#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int len1 = num1.length(), len2 = num2.length();
        string res(len1+len2, '0');
        for(int i = len1-1; i>=0; i--){
            int jinwei = 0;
            for(int j = len2-1; j>=0; j--){
                int cache = res[i+j+1] - '0' + (num1[i] - '0') * (num2[j] - '0') + jinwei;
                res[i+j+1] = cache % 10 + '0';
                jinwei = cache / 10;
            }
            res[i] += jinwei;
        }
        return res.substr(res.find_first_not_of('0'));
    }
};
