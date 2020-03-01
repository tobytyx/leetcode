#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = subTreeHeigh(root->left);
        if(left < 0) return false;
        int right = subTreeHeigh(root->right);
        if(right < 0) return false;
        if(abs(left - right) > 1) return false;
        return true;
    }

    int subTreeHeigh(TreeNode*root){
        if(root == NULL) return 0;
        int left = subTreeHeigh(root->left);
        if(left < 0) return -1;
        int right = subTreeHeigh(root->right);
        if(right < 0) return -1;
        if(left > right){
            if(left - right > 1) return -1;
            return left+1;
        }
        if(right - left > 1) return -1;
        return right + 1;
    }
};
