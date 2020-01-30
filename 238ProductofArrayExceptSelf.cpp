# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return vector<int>();
        vector<int> res(len, 0);
        res[0] = 1;
        int left = nums[0];
        for(int i=1; i<len; i++){
            res[i] = left;
            left *= nums[i];
        }
        int right = nums[len-1];
        for(int i=len-2; i>=0; i--){
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.productExceptSelf(nums);
    for(auto i: res){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
