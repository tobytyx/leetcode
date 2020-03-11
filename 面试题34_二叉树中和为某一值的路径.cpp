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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> cache;
        subPathSum(res, cache, root, 0, sum);
        return res;
    }

    void subPathSum(vector<vector<int>>& res, vector<int>& cache, TreeNode* root, int count, int sum){
        count = count + root->val;
        cache.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(count == sum){
                res.push_back(cache);
            }
            cache.pop_back();
            return;
        }
        if(root->left != NULL){
            subPathSum(res, cache, root->left, count, sum);
        }
        if(root->right != NULL){
            subPathSum(res, cache, root->right, count, sum);
        }
        cache.pop_back();
        return;
    }
};