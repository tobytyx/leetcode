#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len < 3) return nums[0];
        int max_count = 1, max_e = nums[0];
        for(int i=1; i<len; i++){
            if(nums[i] == max_e) max_count++;
            else max_count--;
            if(max_count <= 0){
                max_count = 1;
                max_e = nums[i];
            }
        }
        return max_e;
    }
};