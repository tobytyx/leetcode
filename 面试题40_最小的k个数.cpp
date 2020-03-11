#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        int len = arr.size();
        if(k < 1 || len == 0) return res;
        if(len <= k) return arr;
        multiset<int, greater<int>> int_set;
        for(int i=0; i<len; i++){
            if(int_set.size() < k) int_set.insert(arr[i]);
            else{
                auto iter = int_set.begin();
                if(*iter > arr[i]){
                    int_set.erase(iter);
                    int_set.insert(arr[i]);
                }
            }
        }
        res.insert(res.end(), int_set.begin(), int_set.end());
        return res;
    }
};

int main(){
    vector<int> arr = {0,0,1,2,4,2,2,3,1,4};
    Solution s;
    vector<int> res = s.getLeastNumbers(arr, 8);
    return 0;
}
