# include <iostream>
# include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int max_value = 0;
    int maxSubPath(TreeNode* node){
        int left_max = 0, right_max = 0, node_max = node->val;
        if (node->left != NULL)
            left_max = maxSubPath(node->left);
        if (node->right != NULL)
            right_max = maxSubPath(node->right);
        if (left_max > 0)
            node_max = node_max + left_max;
        if (right_max > 0)
            node_max = node_max + right_max;
        this->max_value = max(this->max_value, node_max);
        if (left_max>0 || right_max>0)
            return max(left_max, right_max) + node->val;
        return node->val;
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        this->max_value = root->val;
        this->maxSubPath(root);
        return this->max_value;
    }
};

int main(){
    TreeNode a(-10), b(9), c(20), d(15), e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    Solution s;
    int max_v = s.maxPathSum(&a);
    printf("max: %d", max_v);
    return 0;
}