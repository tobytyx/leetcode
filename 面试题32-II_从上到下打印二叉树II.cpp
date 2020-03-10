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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        deque<TreeNode*> q(1, root);
        while(!q.empty()){
            int len = q.size();
            vector<int> cache;
            for(int i=0; i<len; i++){
                TreeNode *cur = q.back();
                q.pop_back();
                cache.push_back(cur->val);
                if(cur->left != NULL) q.push_front(cur->left);
                if(cur->right != NULL) q.push_front(cur->right);
            }
            res.push_back(cache);
        }
        return res;
    }
};