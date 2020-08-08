#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        int w = 1, res=0;
        vector<int> cache(len, 0);
        while(w < len){
            for(int i=0; i+w*2<len; i+=w*2){
                int left=i, right=i+w, pos=i;
                while(left<i+w && right<i+2*w){
                    if(nums[left] > nums[right]){
                        res += (right-i-w);
                        cache[pos++] = nums[right++];
                    }
                    else{
                        cache[pos++] = nums[left++];
                    }
                }
            }
        }
    }
};

