#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k > n || k == 0 || n == 0) return res;
        vector<int> nums(n, 0);
        for(int i = 0; i<n; i++){
            nums[i] = i+1;
        }
        vector<int> cache;
        comb(res, nums, 0, cache, n, k);
        return res;
    }

    void comb(vector<vector<int>> &res, vector<int> &nums, int index, vector<int> &cache, int n, int k){
        if(cache.size() == k){
            res.push_back(cache);
            return;
        }
        for(int i=index; i<n; i++){
            cache.push_back(nums[i]);
            comb(res, nums, i+1, cache, n, k);
            cache.pop_back();
        }
    }
};
