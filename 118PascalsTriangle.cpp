# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas;
        if(numRows == 0) return pas;
        pas.push_back(vector<int>(1, 1));
        if(numRows == 1) return pas;
        pas.push_back(vector<int>(2, 1));
        if(numRows == 2) return pas;
        for(int i=2; i<numRows; i++){
            vector<int> last = pas.back();
            vector<int> t(1, 1);
            for(int j=1; j<i; j++){
                t.push_back(last[j-1] + last[j]);
            }
            t.push_back(1);
            pas.push_back(t);
        }
        return pas;
    }
};