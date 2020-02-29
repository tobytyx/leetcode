#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n < 1) return res;
        TreeNode* head = new TreeNode(1);
        res.push_back(head);
        for(int i=2; i<=n; i++){
            int last = res.size();
            for(int j=0; j<last; j++){
                TreeNode* i_node = new TreeNode(i);
                TreeNode* cur = res.back(), *head = cur;
                res.pop_back();
                i_node->left = clone(cur);
                res.insert(res.begin(), i_node);
                while(cur->right != NULL){
                    TreeNode* i_node = new TreeNode(i);
                    TreeNode* cur_right = cur->right;
                    cur->right = i_node;
                    i_node->left = cur_right;
                     res.insert(res.begin(), clone(head));
                    cur->right = cur_right;
                    delete i_node;
                    cur = cur->right;
                }
                cur->right = new TreeNode(i);
                 res.insert(res.begin(), head);
            }
        }
        return res;
    }

    TreeNode* clone(TreeNode* head){
        if(head == NULL) return NULL;
        TreeNode* node = new TreeNode(head->val);
        node->left = clone(head->left);
        node->right = clone(head->right);
        return node;
    }
};