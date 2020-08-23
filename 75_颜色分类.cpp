#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int left = -1, right = len, i=0;
        while(i < right){
            if(nums[i] == 0){
                left++;
                swap(nums[i], nums[left]);
                i++;
            }
            else if(nums[i] == 2){
                right --;
                swap(nums[i], nums[right]);
            }
            else i++;
        }
    }
};