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
    int moves = 0;
    int solve(TreeNode* root){
        if(root == nullptr) return 0;

        int leftCoin = solve(root->left);
        if(leftCoin !=0)    moves += abs(leftCoin);
        int rightCoin = solve(root->right);
        if(rightCoin != 0)  moves += abs(rightCoin);

        return leftCoin + rightCoin + root->val - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        solve(root);
        return moves;
    }
};