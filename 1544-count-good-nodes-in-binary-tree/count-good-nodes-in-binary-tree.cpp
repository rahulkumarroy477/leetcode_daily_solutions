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
    int solve(TreeNode* root, int maxi){
        if(root==nullptr)   return 0;

        int ans = 0;
        if(root->val>=maxi){
            maxi = root->val;
            ans++;
        }
        ans += solve(root->left,maxi);
        ans += solve(root->right,maxi);

        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};