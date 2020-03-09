#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int first = 0, second = 1;
        if(n == 0) return 0;
        if(n == 1) return 1;
        int val = 0;
        for(int i=2; i<=n; i++){
            val = (first + second) % 1000000007;
            first = second;
            second = val;
        }
        return val;
    }
};