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
    unordered_map<int,int> mp;

    int myfun(TreeNode* root, int& sum){
        if(root==NULL) return 0;
        sum=root->val+myfun(root->left,sum)+myfun(root->right,sum);
        mp[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int sum = 0;
        myfun(root,sum);

        int maxfreq = INT_MIN;
        for(auto& i:mp){
            int freq=i.second;
            maxfreq=max(maxfreq,freq);
        }
        for(auto& i:mp){
            int freq=i.second;
            if(freq==maxfreq){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};