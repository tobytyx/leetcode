# include <iostream>
# include <algorithm>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        TreeNode* root = build(preorder, 0, inorder, 0, preorder.size());
        return root;
    }

    TreeNode* build(vector<int>& preorder, int pre_pos, vector<int>& inorder, int in_pos, int index){
        if(index <= 0) return NULL;
        TreeNode* head = new TreeNode(preorder[pre_pos]);
        if(index == 1) return head;
        int i = 0;
        for(; i<index; i++){
            if(inorder[in_pos+i] == preorder[pre_pos]) break;
        }
        if(i == index) return NULL;
        head->left = build(preorder, pre_pos+1, inorder, in_pos, i);
        head->right = build(preorder, pre_pos+i+1, inorder, in_pos+i+1, index-i-1);
        return head;
    }
};

int main(){
    return 0;
}