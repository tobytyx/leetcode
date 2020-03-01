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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        deque<TreeNode*> q;
        q.push_front(root);
        while(!q.empty()){
            TreeNode* last = q.front(), *cur = q.back();
            q.pop_back();
            vector<int> level;
            while(cur != last){
                level.push_back(cur->val);
                if(cur->left != NULL)
                    q.push_front(cur->left);
                if(cur->right != NULL)
                    q.push_front(cur->right);
                cur = q.back();
                q.pop_back();
            }
            level.push_back(cur->val);
            if(cur->left != NULL)
                q.push_front(cur->left);
            if(cur->right != NULL)
                q.push_front(cur->right);
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};