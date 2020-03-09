#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        unordered_map<int, vector<pair<int, int>>> map;
        int len = nums.size();
        if(len < 4) return res;
        // O(n^2)
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                int t = nums[i] + nums[j];
                if(map.find(t) == map.end()) map[t] = vector<pair<int, int>>();
                map[t].push_back(pair(i, j));
            }
        }
        for(auto iter: map){
            int t = target - iter.first;
            if(map.find(t) != map.end()){
                for(auto pair_1: iter.second){
                    for(auto pair_2: map[t]){
                        if(pair_1.first == pair_2.first || pair_1.first == pair_2.second ||
                        pair_1.second == pair_2.first || pair_1.second == pair_2.second) continue;
                        vector<int> r = {nums[pair_1.first], nums[pair_1.second], nums[pair_2.first], nums[pair_2.second]};
                        sort(r.begin(), r.end());
                        res.push_back(r);
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        auto next_iter = unique(res.begin(), res.end());
        res.erase(next_iter, res.end());
        return res;
    }
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len-3; i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1; j<len-2; j++){
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                int left=j+1, right=len-1;
                while(left < right){
                    if(left>j+1 && nums[left-1]==nums[left]){
                        left++;
                        continue;
                    }
                    if(right<len-1 && nums[right+1]==nums[right]){
                        right--;
                        continue;
                    }
                    
                    if(nums[i] + nums[j] + nums[left] + nums[right] == target){
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if(nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else left++;
                }
            }
        }
        return res;
    }
};