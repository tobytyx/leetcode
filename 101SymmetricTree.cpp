# include <iostream>
# include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root->left);
        q2.push(root->right);
        while(not q1.empty() and not q2.empty()){
            TreeNode* p = q1.front();
            q1.pop();
            TreeNode* q = q2.front();
            q2.pop();
            if (p == NULL && q == NULL)
                continue;
            if (p == NULL || q == NULL)
                return false;
            if (p->val != q->val){
                return false;
            }
            q1.push(p->left);
            q2.push(q->right);
            q1.push(p->right);
            q2.push(q->left);
        }
        return true;
    }
};


int main(){
    Solution s;
    s.isSymmetric(NULL);
    return 0;
}
