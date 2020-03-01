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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        TreeNode* root = buildSubTree(nums, 0, nums.size()-1);
        return root;
    }

    TreeNode* buildSubTree(vector<int>& nums, int left, int right){
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(mid > left)
            root->left = buildSubTree(nums, left, mid-1);
        if(right > mid)
            root->right = buildSubTree(nums, mid+1, right);
        return root;
    }
};