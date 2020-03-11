#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> cache(len+1, 0);
        int res = nums[0];
        for(int i=0; i<len; i++){
            cache[i+1] = max(nums[i], (nums[i]+cache[i]));
            res = max(res, cache[i+1]);
        }
        return res;
    }
};