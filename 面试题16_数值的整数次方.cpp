#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        int sig = 1;
        if(n < 0){
            sig = -1;
            n = -(n+1);
        }
        double res = mySubPow(x, n);
        if(sig == 1) return res;
        return 1.0/(res*x);
    }

    double mySubPow(double x, int n){
        if(n==0) return 1;
        if(n == 1) return x;
        double res = myPow(x, n>>1);
        res *= res;
        if(n & 0x1){
            res *= x;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.myPow(2.0, -2) <<endl;
    return 0;
}