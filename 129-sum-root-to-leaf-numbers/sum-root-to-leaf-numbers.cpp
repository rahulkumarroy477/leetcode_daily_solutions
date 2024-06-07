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
    void solve(TreeNode* root,vector<int> &paths,int &num){
        if(root->left==nullptr and root->right == nullptr){
            num *=10;
            num += root->val;
            paths.push_back(num);
            num -= root->val;
            num /= 10;
            return;
        }
        
        num *=10;
        num += root->val;
        if(root->left)
            solve(root->left,paths,num);
        if(root->right)
            solve(root->right,paths,num);
        
        num -= root->val;
        num /= 10;
        
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        
        vector<int> paths;
        int num = 0;
        solve(root,paths,num);
        
        
        int ans = 0;
        for(const auto &x:paths){
            ans += x;
        }
        
        return ans;
    }
};