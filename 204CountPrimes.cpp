# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<int> nums(n, 0);
        int count = 0;
        for(int i=2; i<n; i++){
            if(!nums[i]){
                count++;
                for(int j=1; i*j<n; j++)
                    nums[i*j] = 1;
            }
        }
        return count;
    }
};
