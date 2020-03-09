#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size(), len2 = inorder.size();
        if(len1 == 0 || len2 == 0 || len1 != len2) return NULL;
        return buildSubTree(preorder, inorder, 0, 0, len2);
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int pre_pos, int pos, int index){
        TreeNode* root = new TreeNode(preorder[pre_pos]);
        if(index == 0) return root;
        int i = 0;
        while(i<index){
            if(inorder[pos+i] == preorder[pre_pos]) break;
            i++;
        }
        if(i == index) return root;
        root->left = buildSubTree(preorder, inorder, pre_pos+1, pos, i);
        root->right = buildSubTree(preorder, inorder, pre_pos+i+1, pos+i+1, index-i-1);
        return root;
    }
};

int main(){
    Solution s;
    string str = "123 retrt ";
    
    return 0;
}
