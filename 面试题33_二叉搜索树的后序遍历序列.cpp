#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size();
        if(len < 2) return true;
        return verifySubTree(postorder, 0, len-1);
    }

    bool verifySubTree(vector<int>& postorder, int begin, int end){
        if(begin+1 >= end) return true;
        int i = begin;
        while(i<=end-1){
            if(postorder[i] > postorder[end]) break;
            i++;
        }
        int j=i;
        while(j<=end-1){
            if(postorder[j] < postorder[end]) return false;
            j++;
        }
        bool left=true, right=true;
        if(i > begin) left = verifySubTree(postorder, begin, i-1);
        if(i < end-1) right = verifySubTree(postorder, i, end-1);
        return (left && right);
    }
};

int main(){
    vector<int> postorder = {4,8,6,12,16,14,10};
    Solution s;
    cout << s.verifyPostorder(postorder) << endl;
    return 0;
}
