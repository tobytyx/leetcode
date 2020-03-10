#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int line = matrix.size();
        if(line == 0) return res;
        int row = matrix[0].size();
        if(row == 0) return res;
        int m_min = 0, m_max = line-1, n_min = 0, n_max = row-1;
        while(m_min < m_max && n_min < n_max){
            for(int j=n_min; j<=n_max; j++) res.push_back(matrix[m_min][j]);
            m_min++;
            for(int i=m_min; i<=m_max; i++) res.push_back(matrix[i][n_max]);
            n_max--;
            for(int j=n_max; j>=n_min; j--) res.push_back(matrix[m_max][j]);
            m_max--;
            for(int i=m_max; i>=m_min; i--) res.push_back(matrix[i][n_min]);
            n_min++;
        }
        if(m_min == m_max){
            for(int j=n_min; j<=n_max; j++) res.push_back(matrix[m_min][j]);
        }
        else if(n_min == n_max){
            for(int i=m_min; i<=m_max; i++) res.push_back(matrix[i][n_max]);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for(int i: res) printf("%d ", i);
    printf("\n");
    return 0;
}
