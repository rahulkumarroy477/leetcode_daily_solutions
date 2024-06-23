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
    int cameras = 0;
    int haveCamera(TreeNode* root){
        if(root==nullptr)   return 1;

        int left = haveCamera(root->left);
        int right = haveCamera(root->right);

        if(left == -1 || right == -1){
            cameras++;
            return 0;
        }
        if(left == 0 || right == 0){
            return 1;
        }

        // left and right already covered 
        // parent will handle it
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(root == nullptr) return 0;
        // root not handled
        if(haveCamera(root)==-1)    cameras++;
        return cameras;
    }
};