#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        vector<TreeNode*> stack(1, root);
        int pre = INT_MIN;
        bool first = true;
        TreeNode* p = root->left;
        while(!stack.empty() || p != NULL){
            while(p != NULL){
                stack.push_back(p);
                p = p->left;
            }
            p = stack.back();
            stack.pop_back();
            if(!first && pre >= p->val) return false;
            if(first) first = false;
            pre = p->val;
            p = p->right;
        }
        return true;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    cout << s.isValidBST(root) << endl;
    return 0;
}
