#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 1) return 1;
        vector<int> cache(n+1, 0);
        cache[1] = 1;
        cache[0] = 1;
        for(int i=2; i<=n; i++){
            int buff = 0;
            for(int j=1; j<=i; j++){
                buff = buff + cache[j-1] * cache[i-j];
            }
            cache[i] = buff;
        }
        return cache[n];
    }
};

int main(){
    Solution s;
    printf("%d\n", s.numTrees(3));
    return 0;
}
