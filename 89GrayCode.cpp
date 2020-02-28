#include<iostream>
#include<vector>
#include<math.h>
#include<bitset>
using namespace std;


class Solution {
public:
    vector<int> grayCode(int n) {
        bitset<32> bit_v;
        vector<int> res;
        gray(res, bit_v, n);
        return res;
    }

    void gray(vector<int>& res, bitset<32>& bit_v, int k){
        if(k == 0){
            res.push_back(bit_v.to_ulong());
        }
        else{
            gray(res, bit_v, k-1);
            bit_v.flip(k-1);
            gray(res, bit_v, k-1);
        }
    }
};


int main(){
    Solution s;
    vector<int> res = s.grayCode(2);
    for(int i: res){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
