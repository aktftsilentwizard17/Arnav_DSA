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
int diameter = 0;
private:
    int myfun(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int lh=myfun(node->left);
        int rh=myfun(node->right);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        myfun(root);
        return diameter;
    }
};