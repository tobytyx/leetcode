#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        if(len != popped.size()) return false;
        if(len == 0) return true;
        vector<int> stack;
        int i=0, j=0;
        while(i<=len && j<len){
            if(stack.empty() || stack.back() != popped[j]){
                if(i == len) return false;
                stack.push_back(pushed[i]);
                i++;
            }
            else{
                stack.pop_back();
                j++;
            }
        }
        cout << i << j << endl;
        if(i == j && i == len) return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    cout << s.validateStackSequences(pushed, popped) << endl;
    return 0;
}
