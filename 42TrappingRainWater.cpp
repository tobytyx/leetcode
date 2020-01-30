# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 3) return 0;
        int left=0, right=len-1, max_left=0, max_right=0, res=0;
        while (left<right){
            if(height[left] <= height[right]){
                if(height[left] > max_left) max_left = height[left];
                res += (max_left-height[left]);
                left++;
            }
            else{
                if(height[right] > max_right) max_right = height[right];
                res += (max_right-height[right]);
                right--;
            }
        }
        return res;
    }
};
