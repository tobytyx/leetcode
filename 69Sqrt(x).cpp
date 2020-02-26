#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        if(x < 4) return 1;
        int right = x / 2, left = 2;
        while(left < right){
            int mid = (left + right) / 2;
            if(mid == x/mid) return mid;
            if(mid > x/mid){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        if(left > x/left) return left-1;
        return left;
    }
};
