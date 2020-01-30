# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int len = nums.size();
        if (len == 0) return res;
        int i = 0, j = len-1, mid = 0;
        while (i < j){
            mid = (i + j) / 2;
            if (nums[mid] < target){
                i = mid + 1;
            }
            else{
                j = mid;
            }
        }
        if (nums[i] != target) return res;
        res[0] = i;
        j = len - 1;
        while (i < j){
            mid = (i + j - 1) / 2 + 1;
            if (nums[mid] > target){
                j = mid - 1;
            }
            else{
                i = mid;
            }
        }
        res[1] = j;
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,6,6,6,7};
    vector<int> res = s.searchRange(nums, 6);
    printf("%d,%d\n", res[0], res[1]);
    return 0;
}
