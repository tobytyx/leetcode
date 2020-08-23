# include <iostream>
# include <queue>
# include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* cur = NULL;
        TreeNode* pre = root;
        vector<TreeNode*> s;
        s.push_back(root);
        while(!s.empty()){
            cur = s.back();
            s.pop_back();
            if (cur->right != NULL){
                s.push_back(cur->right);
            }
            if (cur->left != NULL){
                s.push_back(cur->left);
            }
            if (cur == root){
                continue;
            }
            pre->right = cur;
            pre->left = NULL;
            pre = cur;
        }
        return;
    }
};


int main(){
    Solution s;
    TreeNode a(1), b(2), c(3),d(4), e(5), f(6);
    a.left = &b;
    a.right = &e;
    b.left = &c;
    b.right = &d;
    e.right = &f;
    s.flatten(&a);
    TreeNode* cur = &a;
    while (cur != NULL){
        printf("%d-", cur->val);
        cur = cur->right;
    }
    return 0;
}
