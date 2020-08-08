#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max_area = 0;
        int i = 0, j = len-1;
        while(i < j){
            if(height[i] < height[j]){
                max_area = max(max_area, height[i] * (j-i));
                i++;
            }
            else{
                max_area = max(max_area, height[j] * (j-i));
                j--;
            }
        }
        return max_area;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max_area = 0, i=0, j=len-1;
        while (i < j){
            if(height[i] < height[j]){
                max_area = max(max_area, height[i] * (j-i));
                i ++;
            }
            else{
                max_area = max(max_area, height[j] * (j-i));
                j --;
            }
        }
        return max_area;
    }
};