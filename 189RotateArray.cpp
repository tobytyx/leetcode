# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < 2) return;
        int num_rotate = 0, start = 0, cur = 0;
        while (num_rotate < len){
            cur = (start+k) % len;
            int buff = nums[cur];
            nums[cur] = nums[start];
            num_rotate++;
            if(num_rotate == len) return;
            while(start != cur){
                cur = (cur+k) % len;
                swap(buff, nums[cur]);
                num_rotate++;
                if(num_rotate == len) return;
            }
            start++;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    s.rotate(nums, 3);
    for(auto i: nums){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}