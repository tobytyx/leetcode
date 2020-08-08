#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len == 0) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len-2; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int left = i+1, right = len-1;
            while(left < right){
                if(left > i+1 && nums[left-1] ==nums[left]){
                    left++;
                    continue;
                }
                if(right < len - 1 && nums[right] == nums[right+1]){
                    right--;
                    continue;
                }
                if(nums[i] + nums[left] + nums[right] == 0){
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else
                    left++;
            }
        }
        
        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len-2; i++){
            int two_sum = -nums[i], left=i+1, right=len-1;
            if(i>0 && nums[i-1] == nums[i]) continue;
            while(left < right){
                if(left > i+1 && nums[left] == nums[left-1]) left++;
                else if(right < len-1 && nums[right] == nums[right+1]) right--;
                else{
                    if(nums[left] + nums[right] == two_sum){
                        res.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if(nums[left] + nums[right] > two_sum) right--;
                    else left++;
                }
                
            }
        }
        return res;
    }
};


int main(){
    vector<int> nums = {1,0,-1,-1};
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    return 0;
}