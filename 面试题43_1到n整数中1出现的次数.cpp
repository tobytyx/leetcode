#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        long i = 1;
        while(n / i != 0) {
            long high = n / (10 * i);
            long cur = (n / i) % 10;
            long low = n - (n / i) * i;
            if(cur == 0) {
                count += high * i;
            }else if(cur == 1) {
                count += high * i + (low + 1);
            }else {
                count += (high + 1) * i;
            }
            i = i * 10;
        }
        return count;
    }
};