#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return;
        int k=-1;
        for(int i=0; i<len-1; i++){
            if(nums[i] < nums[i+1]){
                k = i;
            }
        }
        if (k == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            int l = k+1;
            for(int i=l; i<len; i++){
                if(nums[k] < nums[i]){
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin()+k+1, nums.end());
        }
    }
};