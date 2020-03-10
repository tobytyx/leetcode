#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return nums;
        int left = 0, right = len-1;
        while(left < right){
            while(left < right && (nums[left] & 1) == 1) left++;
            while(left < right && (nums[right] & 1) == 0) right--;
            if(left < right){
                swap(nums[left], nums[right]);
            }
            left++;
            right--;
        }
        return nums;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    vector<int> res = s.exchange(nums);
    for(int i:res){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}