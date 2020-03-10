#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;
        long max = 1;
        while(n >= 5){
            max = (max * 3) % int(1e9+7);
            n-=3;
        }
        return (max * n) % int(1e9+7);
    }
};