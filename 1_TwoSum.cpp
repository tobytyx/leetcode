#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        int len = nums.size();
        if(len == 0) return res;
        for(int i=0; i<len; i++){
            m[target - nums[i]] = i;
        }
        for(int i=0; i<len; i++){
            if(m.find(nums[i]) != m.end() && i != m[nums[i]]){
                res.push_back(i);
                res.push_back(m[nums[i]]);
                return res;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        if(len < 2) return res;
        unordered_map<int, int> m;
        for(int i=0; i<len; i++){
            if(m.find(nums[i]) != m.end()){
                res.push_back(i);
                res.push_back(m[nums[i]]);
                return res;
            }
            m[target-nums[i]] = i;
        }
        return res;
    }
};

int main(){
    int m = 0;
    cin >> m;
    vector<int> nums;
    for(int i=0; i<m; i++){
        int num = 0;
        cin >> num;
        nums.push_back(num);
    }
    int target = 0;
    cin >> target;
    Solution2 s;
    vector<int> res =  s.twoSum(nums, target);
    for(int r: res){
        printf("%d ", r);
    }
    printf("\n");
    return 0;
}