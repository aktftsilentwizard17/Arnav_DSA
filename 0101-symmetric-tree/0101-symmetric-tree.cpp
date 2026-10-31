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
private:
    bool mirror(TreeNode* n1, TreeNode* n2){
        if(n1 == nullptr && n2 == nullptr){
            return true;
        }
        if(n1 == nullptr || n2 == nullptr || n1->val != n2->val){
            return false;
        }
        return mirror(n1->left, n2->right) && mirror(n1->right, n2->left); //check the pattern
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return mirror(root->left, root->right);
    }
};