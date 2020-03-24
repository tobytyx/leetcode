#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str_nums;
        for(int i: nums){
            str_nums.push_back(to_string(i));
        }
        sort(str_nums.begin(), str_nums.end(), cmp);
        string res;
        for(string s: str_nums){
            res += s;
        }
        return res;
    }
    
    static bool cmp(const string& a, const string& b){
        return a+b < b+a;
    }
};

int main(){
    vector<int> nums = {12, 21, 1};
    Solution s;
    cout << s.minNumber(nums) << endl;
    return 0;
}