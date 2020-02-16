# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        for(int n: nums1){
            if(map.find(n) == map.end()) map[n] = 0;
            map[n]++;
        }
        for(int n: nums2){
            if(map.find(n) != map.end() && map[n] > 0){
                map[n]--;
                res.push_back(n);
            }
        }
        return res;
    }
};