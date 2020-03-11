#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if(k < 1 || len == 0) return 0;
        multiset<int, less<int>> int_set;
        for(int i=0; i<len; i++){
            if(int_set.size() < k) int_set.insert(nums[i]);
            else{
                auto iter = int_set.begin();
                if(*iter < nums[i]){
                    int_set.erase(iter);
                    int_set.insert(nums[i]);
                }
            }
        }
        return *int_set.begin();
    }
};

