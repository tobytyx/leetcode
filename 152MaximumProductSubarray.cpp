# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return 0;
        int max_product = nums[0], buff_max = nums[0], buff_min = nums[0];
        for(int i=1; i<len; i++){
            if(nums[i] < 0){
                swap(buff_max, buff_min);
            }
            buff_max = max(buff_max*nums[i], nums[i]);
            buff_min = min(buff_min*nums[i], nums[i]);
            max_product = max(max_product, buff_max);
        }
        return max_product;
    }
};

int main(){
    vector<int> nums = {2, 3, -2, 4};
    Solution s;
    printf("%d\n", s.maxProduct(nums));
    return 0;
}