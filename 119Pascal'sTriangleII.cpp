#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        deque<int> q;
        for(int i=0; i<=rowIndex; i++){
            int pre = 0;
            int len = q.size();
            for(int j=0; j<len; j++){
                q.push_front(pre + q.back());
                pre = q.back();
                q.pop_back();
            }
            q.push_front(1);
        }
        for(int i: q){
            res.push_back(i);
        }
        return res;
    }
};