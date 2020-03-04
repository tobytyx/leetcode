#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int closest = abs(target - nums[0] - nums[1] - nums[2]);
        int res = nums[0] + nums[1] + nums[2];
        for(int fst = 0; fst < len-2; fst++){
            int snd = fst+1, trd = len-1;
            while (snd < trd){
                int cur = nums[fst] + nums[snd] + nums[trd] - target;
                if(cur == 0) return target;
                if (cur > 0){
                    if (closest > cur){
                        closest = cur;
                        res = nums[fst] + nums[snd] + nums[trd];
                    }
                    trd--;
                }
                else{
                    if(closest > -cur){
                        closest = -cur;
                        res = nums[fst] + nums[snd] + nums[trd];
                    }
                    snd++;
                }
            }            
        }
        return res;
    }
    int threeSumClosest2(vector<int>& nums, int target){
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int cls = 0;
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
                int sum = nums[i] + nums[left] + nums[right];
                if(target == sum){
                    return target;
                }
                else if(sum > target){
                    if(sum - target < closest){
                        closest = sum - target;
                        cls = sum;
                    }
                    right--;
                }
                else{
                    if(target - sum < closest){
                        closest = target - sum;
                        cls = sum;
                    }
                    left++;
                }
            }
        }
        return cls;
    }

};

int main(){
    Solution s;
    vector<int> nums = {0, 2, 1, -3};
    printf("%d\n", s.threeSumClosest(nums, 1));
    return 0;
}
