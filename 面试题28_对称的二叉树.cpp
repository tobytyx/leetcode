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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL)  return true;
        if(root->left == NULL || root->right == NULL)  return false;
        vector<TreeNode*> q1(1, root->left), q2(1, root->right);
        while(!q1.empty() && !q2.empty()){
            TreeNode* r1 = q1.back(), *r2 = q2.back();
            q1.pop_back();
            q2.pop_back();
            if(r1->val != r2->val) return false;
            if(r1->left == NULL || r2->right == NULL){
                if(r1->left != NULL || r2->right != NULL) return false;
            }
            else{
                q1.push_back(r1->left);
                q2.push_back(r2->right);
            }
            if(r1->right == NULL || r2->left == NULL){
                if(r1->right != NULL || r2->left != NULL) return false;
            }
            else{
                q1.push_back(r1->right);
                q2.push_back(r2->left);
            }
        }
        if(!q1.empty() || !q2.empty()) return false;
        return true;
    }
};