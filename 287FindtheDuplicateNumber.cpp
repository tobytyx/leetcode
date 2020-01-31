# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]], slow = nums[0];
        while (fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while (fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2,2,4};
    int i = s.findDuplicate(nums);
    printf("%d\n", i);
    return 0;
}