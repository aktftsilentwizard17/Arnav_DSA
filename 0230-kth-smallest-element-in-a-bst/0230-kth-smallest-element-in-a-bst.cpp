/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorder;
    int kthSmallest(TreeNode* root, int k) {
        inordertraversal(root);
        sort(inorder.begin(),inorder.end());
        return inorder[k-1];
    }
    void inordertraversal(TreeNode* node){
        if(node==NULL) return;
        inordertraversal(node->left);
        inorder.push_back(node->val);
        inordertraversal(node->right);
    }
};