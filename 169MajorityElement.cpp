# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        unordered_map<int, int> map;
        for(int i=0; i<len; i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 0;
            }
            map[nums[i]] ++;
        }
        int max_count = 0, max_elen = 0;
        for(unordered_map<int,int>::iterator iter = map.begin(); iter != map.end(); iter++){
            if(iter->second > max_count){
                max_elen = iter->first;
                max_count = iter->second;
            }
        }
        return max_elen;
    }
    int majorityElement2(vector<int>& nums){
        int len = nums.size();
        if(len == 1) return nums[0];
        int count=1, num=nums[0];
        for(int i=1; i<len; i++){
            if(count==0){
                count = 1;
                num = nums[i];
            }
            else if(nums[i] == num) count++;
            else count--;
        }
        return num;
    }
};