# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int n: nums){
            if(map.find(n) == map.end())
                map[n] = 0;
            map[n]++;
        }
        vector<int> res;
        for(int i=0; i<k; i++){
            int max_count=0, max_num=0;
            for(auto iter: map){
                if(iter.second > max_count){
                    max_count = iter.second;
                    max_num = iter.first;
                }
            }
            res.push_back(max_num);
            map[max_num] = 0;
        }
        return res;
    };

    vector<int> topKFrequent2(vector<int>& nums, int k){
        unordered_map<int, int> map;
        vector<int> res;
        int m = 0, max_num = 0;
        for(int n: nums){
            if(map.find(n) == map.end()){
                map[n] = 0;
                m++;
            }
            map[n]++;
        }
        for(auto iter: map){
            max_num = max(max_num, iter.second);
        }
        vector<vector<int>> bucket(max_num+1, vector<int>());
        for(auto iter: map){
            bucket[iter.second].push_back(iter.first);
        }
        for(int i=max_num; i>0; i--){
            if(bucket[i].size() == 0) continue;
            int len = k - res.size();
            if(bucket[i].size() >= len){
                res.insert(res.end(), bucket[i].begin(), bucket[i].begin()+len);
                break;
            }
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> res = s.topKFrequent2(nums, 2);
    for(auto i: res){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}