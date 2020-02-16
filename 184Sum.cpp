# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_map>
# include <unordered_set>
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
};
