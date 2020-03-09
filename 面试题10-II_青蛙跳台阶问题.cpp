#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        int first = 1, second = 2;
        if(n == 0) return 1;
        if(n < 3) return n;
        int val = 0;
        for(int i=3; i<=n; i++){
            val = (first + second) % int(1e9+7);
            first = second;
            second = val;
        }
        return val;
    }
};