# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        if(len == 2){
            if(nums[0] > nums[1]) return 0;
            return 1;
        }
        int left = 0, right = len-1;
        while(left < right){
            int mid = (left + right) / 2;
            if((mid == 0 || nums[mid-1] < nums[mid]) && nums[mid] > nums[mid+1]) return mid;
            if(mid == 0 || nums[mid-1] < nums[mid]) left = mid + 1;
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};

