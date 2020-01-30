# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int len = candidates.size();
        if(len == 0) return res;
        sort(candidates.begin(), candidates.end());
        while (candidates.back() > target)
            candidates.pop_back();
        for (auto x: candidates){
            res.push_back(vector<int>(x, 1));
        }
        int max_num = target / candidates[0];
        vector<vector<int>> lists;
        for(int i=1; i<=max_num; i++){
            
        }
    }
};

int main(){
    Solution s;

    return 0;
}
