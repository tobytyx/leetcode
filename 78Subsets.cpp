# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int len_nums = nums.size();
        for (int index = 0; index < len_nums; index++){
            int len = res.size();
            res.push_back(vector<int>(1, nums[index]));
            for (int i=0; i<len; i++){
                vector<int> b(res[i]);
                b.push_back(nums[index]);
                res.push_back(b);
            }
        }
        res.push_back(vector<int>());
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    for (auto re: res){
        for(auto r: re){
            printf("%d ", r);
        }
        printf("\n");
    }
    return 0;
}
