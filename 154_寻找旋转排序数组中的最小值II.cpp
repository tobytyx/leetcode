#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        while(nums.size() > 1 && nums[0] == nums.back()){
            nums.pop_back();
        }
        len = nums.size();
        if(len == 1) return nums[0];
        int left = 0, right = len-1;
        while(left < right && nums[left] > nums[right]){
            int mid = (left + right) / 2;
            if(nums[left] <= nums[mid]){ // 逆序在右边
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return nums[right] < nums[left] ? nums[right] : nums[left];
    }
};