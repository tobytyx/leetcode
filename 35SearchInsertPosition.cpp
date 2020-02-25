#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int low = 0, high = len - 1;
        while(low < high){
            int mid = (high + low) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        if(nums[low] >= target) return low;
        return low+1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    printf("%d\n", s.searchInsert(nums, 5));
    return 0;
}
