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
};

int main(){
    Solution s;
    vector<int> nums = {0, 2, 1, -3};
    printf("%d\n", s.threeSumClosest(nums, 1));
    return 0;
}
