#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        if(nums[0] == target) return true;
        while(!nums.empty() && nums[0] == nums.back())
            nums.pop_back();
        int len = nums.size();
        if(len == 0) return false;
        int left = 0, right = len-1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            if(nums[left] <= nums[mid]){ // 逆序点不在left-mid间
                if(nums[left] <= target && nums[mid] >= target) right = mid; 
                else{
                    left = mid + 1;
                }
            }
            else{ // 逆序点在Left-mid间
                if(nums[mid] <= target && target <= nums[right]) left = mid + 1; 
                else{
                    right = mid;
                }
            }

        }
        if(nums[left] == target) return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,1,1,1};
    cout<< s.search(nums, 3) << endl;
    return 0;
}
