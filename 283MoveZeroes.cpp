# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return;
        int cur = 0, zero_num = 0;
        for(int i=0; i<len; i++){
            if(nums[i] == 0) zero_num ++;
            else{
                nums[cur] = nums[i];
                cur++;
            }
        }
        for(int j=1; j<=zero_num; j++){
            nums[len-j] = 0;
        }
        return;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeroes(nums);
    for(auto i: nums){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}