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
        vector<int> cache(n+1, 0);
        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 3;
        for(int i=4; i<=n; i++){
            int max_dot = 0;
            for(int j=1; j<i; j++){
                max_dot = max(max_dot, cache[j]*cache[i-j]);
            }
            cache[i] = max_dot;
        }
        return cache[n];
    }
};

int main(){
    int n = 10;
    Solution s;
    cout << s.cuttingRope(10) << endl;
    return 0;
}
