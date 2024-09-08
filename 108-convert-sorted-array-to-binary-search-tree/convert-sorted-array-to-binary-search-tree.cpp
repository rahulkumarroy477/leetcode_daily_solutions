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

    TreeNode* fillTree(vector<int>& nums,int l, int r){

        if(l>r) 
            return nullptr;
        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = fillTree(nums,l,mid-1);
        root->right = fillTree(nums,mid+1,r);

        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();

        // if(n == 1)  return new TreeNode(nums[0]);
        return fillTree(nums,0,n-1);

    }
};