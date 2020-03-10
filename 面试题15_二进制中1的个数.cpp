#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count++;
            n = n & (n-1);
        }
        return count;
    }
    int hammingWeight2(uint32_t n){
        unsigned int signal = 1;
        int count = 0;
        while(signal){
            if(n & signal){
                count++;
            }
            signal >>= 1;
        }
        return count;
    }
};