# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return false;
        unordered_map<int, int> map;
        for(int i=0; i<len; i++){
            if(map.find(nums[i]) != map.end()) return true;
            map[nums[i]] = 0;
        }
        return false;
    }
};

int main(){
    Solution s;
    return 0;
}
