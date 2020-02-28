#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        int len = nums.size();
        if(len == 0) return res;
        sort(nums.begin(), nums.end());
        vector<int> cache;
        subset(res, nums, cache, 0);
        return res;
    }

    void subset(vector<vector<int>>& res, vector<int>& nums, vector<int>& cache, int index){
        int len = nums.size();
        for(int i=index; i<len; i++){
            cache.push_back(nums[i]);
            res.push_back(cache);
            subset(res, nums, cache, i+1);
            cache.pop_back();
            while(i+1<len && nums[i]==nums[i+1]){
                i++;
            }
        }
    }
};