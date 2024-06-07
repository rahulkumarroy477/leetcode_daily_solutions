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
    void solve(TreeNode* root,int &num,int &ans){
        if(root->left==nullptr and root->right == nullptr){
            num *=10;
            num += root->val;
            ans += num;
            num -= root->val;
            num /= 10;
            return;
        }
        
        num *=10;
        num += root->val;
        if(root->left)
            solve(root->left,num,ans);
        if(root->right)
            solve(root->right,num,ans);
        
        num -= root->val;
        num /= 10;
        
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        int num = 0;
        solve(root,num,ans);
        
        
        
        return ans;
    }
};