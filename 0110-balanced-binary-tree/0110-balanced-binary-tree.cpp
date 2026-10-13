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
    int myfun(TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int leftheight = myfun(node->left);
        if(leftheight==-1) return -1;

        int rightheight = myfun(node->right);
        if(rightheight==-1) return -1;

        if(abs(leftheight-rightheight)>1) return -1;

        return 1+max(leftheight,rightheight);
    }
public:
    bool isBalanced(TreeNode* root) {
        return myfun(root)!=-1;
    }
};