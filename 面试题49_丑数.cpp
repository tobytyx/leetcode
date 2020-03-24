#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums(n, 0);
        if(n < 0) return 0;
        ugly_nums[0] = 1;
        int len = 1;
        while(len < n){
            int next = -1;
            for(int i=0; i<len; i++){
                if(ugly_nums[i] * 2 > ugly_nums[len-1]){
                    next = ugly_nums[i] * 2;
                    break;
                }
            }
            for(int i=0; i<len; i++){
                if(ugly_nums[i] * 3 > ugly_nums[len-1]){
                    next = min(ugly_nums[i] * 3, next);
                    break;
                }
            }
            for(int i=0; i<len; i++){
                if(ugly_nums[i] * 5 > ugly_nums[len-1]){
                    next = min(ugly_nums[i] * 5, next);
                    break;
                }
            }
            ugly_nums[len++] = next;
        }
        return ugly_nums.back();
    }
};