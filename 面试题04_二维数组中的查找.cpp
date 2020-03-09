#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        int x = n - 1;
        int y = 0;
        while(y < m && x >= 0){
            if(matrix[y][x] == target) return true;
            if(matrix[y][x] > target) x--;
            else y++;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> nums = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution s;
    cout << s.findNumberIn2DArray(nums, 30) << endl;
    return 0;
}
