#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        int left = 0, right = m - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target) left = mid+1;
            else right = mid;
        }
        if(matrix[left][0] > target) m = left - 1;
        else m = left;
        if(m < 0) return false;
        left = 0;
        right = n-1;
        while(left < right){
            int mid = (left + right) / 2;
            if(matrix[m][mid] == target) return true;
            if(matrix[m][mid] < target) left = mid+1;
            else right = mid;
        }
        
        if(matrix[m][left] == target) return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix(2, vector<int>(1, 0));
    matrix[0][0] = 1;
    matrix[1][0] = 3;
    cout << s.searchMatrix(matrix, 3) << endl;
    return 0;
}
