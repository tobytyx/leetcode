#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, number = 1;
        while(i < n){
            int x_min = i/2, x_max = n - i/2 - 1, y_min = i/2, y_max = n - i/2 - 1;
            for(int j = y_min; j <= y_max; j++){
                res[x_min][j] = number++;
            }
            for(int j = x_min + 1; j <= x_max; j++){
                res[j][y_max] = number++;
            }
            for(int j = y_max - 1; j >= y_min; j--){
                res[x_max][j] = number++;
            }
            for(int j = x_max - 1; j > x_min; j--){
                res[j][y_min] = number++;
            }
            i = i + 2;
        }
        return res;
    }
};
