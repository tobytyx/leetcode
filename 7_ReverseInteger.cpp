#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(-10 < x && x < 10) return x;
        int res = 0;
        int symbol = 1;
        if(x < 0){
            res = -(x % 10);
            x = -(x/10);
            symbol = -1;
        }
        while(x > 0){
            int tmp = x % 10;
            x /= 10;
            if((INT_MAX-tmp)/10 < res){
                if(symbol < 0 && (INT_MAX-tmp+1)/10 == res) return INT_MIN;
                return 0;
            }
            res = res * 10 + tmp;
        }
        return res * symbol;
    }
};