#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(m <= 0 || n <= 0 || k < 0) return 0;
        vector<vector<int>> mat = vector(m, vector(n, 0));
        int res = movingSub(mat, m, n, 0, 0, k);
        return res;
    }

    int movingSub(vector<vector<int>>& mat, int m, int n, int x, int y, int k){
        if(x >= m || y >= n || mat[x][y] == 1 || digitSum(x) + digitSum(y) > k) return 0;
        int res = 1;
        mat[x][y] = 1;
        res += movingSub(mat, m, n, x+1, y, k);
        res += movingSub(mat, m, n, x, y+1, k);
        return res;
    }

    int digitSum(int d){
        int sum = 0;
        while(d){
            sum += d % 10;
            d /= 10;
        }
        return sum;
    }
};