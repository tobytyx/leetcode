#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
        int base=1;
        while(n > 9*pow(10,base-1)*base){
            n-=9*pow(10,base-1)*base;
            base++;
        }
        int res = pow(10, base-1) + n/base;
        int mod = n % base;
        if(mod==0)
            return (res-1)%10;
        else
            return res / (int)pow(10,base-mod)%10;
    }
};

int main(){
    Solution s;
    cout << s.findNthDigit(1000) << endl;
    return 0;
}
