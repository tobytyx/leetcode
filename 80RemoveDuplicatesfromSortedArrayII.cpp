#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return len;
        int dump = 0, low = 2;
        if(nums[0] == nums[1]) dump++;
        for(int i=2; i<len; i++){
            if(nums[i] == nums[low-1]) dump++;
            else dump = 0;
            if(dump < 2){
                nums[low] = nums[i];
                low++;
            }
        }
        return low;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,2,3};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
