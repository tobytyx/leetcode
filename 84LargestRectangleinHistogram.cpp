# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 0) return 0;
        if(len == 1) return heights[0];
        heights.push_back(0);
        len = len + 1;
        vector<int> st;
        int max_area = 0;
        for(int i=0; i<len; i++){
            while(!st.empty() && heights[i] < heights[st.back()]){
                int index = st.back();
                st.pop_back();
                int weight = (!st.empty()) ? i - st.back() - 1: i;
                max_area = max(max_area, heights[index] * weight);
            }
            st.push_back(i);
        }
        return max_area;
    }
};

int main(){
    vector<int> heights = {2,1,2};
    Solution s;
    int max_area = s.largestRectangleArea(heights);
    printf("%d\n", max_area);
    return 0;
}