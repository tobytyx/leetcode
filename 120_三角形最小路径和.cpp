#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int level = triangle.size();
        if(level == 0) return 0;
        if(level == 1) return triangle[0][0];
        for(int i=1; i<level-1; i++){
            int len = triangle[i].size();
            for(int j=0; j<len; j++){
                if(j==0) triangle[i][j] += triangle[i-1][j];
                else if(j==len-1) triangle[i][j] += triangle[i-1][j-1];
                else{
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }
        int min_num = triangle[level-1][0] + triangle[level-2][0];
        int len = triangle[level-1].size();
        min_num = min(min_num, triangle[level-1][len-1] + triangle[level-2][len-2]);
        for(int j=1; j<len-1; j++){
            triangle[level-1][j] += min(triangle[level-2][j-1], triangle[level-2][j]);
            min_num = min(min_num, triangle[level-1][j]);
        }
        return min_num;
    }
};