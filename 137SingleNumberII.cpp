#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b0=0, b1=0, reset=0;
        int i;
        int n = nums.size();
        for(i = 0; i<n; i++){
            b1 |= (b0 & nums[i]);
            b0 = b0 ^ nums[i];
            reset = b1 & b0;
            b1 = b1 ^ reset;
            b0 = b0 ^ reset;
        }
        return b0;
    }
};