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
    void solve(TreeNode* root,int height,vector<pair<int,int>> &heightWithNode){
        if(root->left==nullptr and root->right==nullptr){
            heightWithNode.push_back({root->val,height});
            return;
        }
        
        if(root->left)  solve(root->left,height+1,heightWithNode);
        if(root->right) solve(root->right,height+1,heightWithNode);
    }
    int findBottomLeftValue(TreeNode* root) {
        
        if(root->left == nullptr and root->right == nullptr)    return root->val;
        
        // jitte bhi leaf node hai usko height ke sath store karlo
        vector<pair<int,int>> heightWithNode;
        solve(root,0,heightWithNode);
        
        int h = 0, ans = 0;
        for(auto x:heightWithNode){
            int val = x.first;
            int height = x.second;
            if(height>h){
                h = height;
                ans = val;
            }
        }
        return ans;
    }
};