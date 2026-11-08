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
    int countNodes(TreeNode* root) {
        // for O(n), just return 1+count(root->left)+count(root->right)
        // for better than O(n), most prolly O(log²n), use following method

        if(root==nullptr) return 0;
        int lh=0,rh=0;
        TreeNode* l = root;
        TreeNode* r = root;
        while(l!=nullptr){
            lh++;
            l=l->left;
        }
        while(r!=nullptr){
            rh++;
            r=r->right;
        }

        if(lh==rh) return (1<<lh)-1; //perfect tree, 2^h-1 nodes
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};