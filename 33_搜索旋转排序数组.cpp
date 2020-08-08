#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return -1;
        int left=0, right=len-1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(nums[i] < nums[mid])
        }
    }
};
