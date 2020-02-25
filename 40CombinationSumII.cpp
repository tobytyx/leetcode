#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        // int len = candidates.size();
        if(candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        while(!candidates.empty() && candidates.back() > target) candidates.pop_back();
        if(candidates.empty()) return res;
        if(candidates.back() == target) res.push_back(vector<int>(1, target));
        while(!candidates.empty() && candidates.back() == target) candidates.pop_back();
        if(candidates.empty()) return res;
        vector<int> cache;
        comSum(res, candidates, 0, 0, cache, target);
        return res;
    }

    void comSum(vector<vector<int>>& res, vector<int>& candidates, int sum, int index, vector<int>& cache, int target){
        int len = candidates.size();
        for(int i = index; i < len; i++){
            if(sum + candidates[i] == target){
                cache.push_back(candidates[i]);
                res.push_back(cache);
                cache.pop_back();
                return;
            }
            else if(sum + candidates[i] > target){
                return;
            }
            else{
                cache.push_back(candidates[i]);
                comSum(res, candidates, sum+candidates[i], i+1, cache, target);
                while(i < len - 1 && candidates[i] == candidates[i+1]){
                    i++;
                }
                cache.pop_back();
            }
        }
    }
};