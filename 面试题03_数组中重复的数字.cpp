#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        for(int i=0; i<len; i++){
            while(i != nums[i]){
                if(nums[i] == nums[nums[i]]) return nums[i];
                int tmp = nums[i];
                nums[i] = nums[nums[i]];
                nums[tmp] = tmp;
            }
        }
        return 0;
    }
};

int main(){
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    Solution s;
    cout << s.findRepeatNumber(nums) << endl;
    return 0;
}
