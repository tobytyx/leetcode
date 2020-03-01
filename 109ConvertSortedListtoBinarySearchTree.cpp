#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildSubTree(head, NULL);
    }

    TreeNode* buildSubTree(ListNode* head, ListNode* tail){
        if(head == tail) return NULL;
        ListNode* fast = head, *slow = head;
        while(fast != tail && fast->next != tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildSubTree(head, slow);
        root->right = buildSubTree(slow->next, tail);
        return root;
    }
};