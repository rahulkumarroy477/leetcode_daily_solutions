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
    int getMaxIndex(vector<int> &nums, int start, int end) {
        int maxIdx = start;
        for(int i = start; i <= end; i++) {
            if(nums[maxIdx] < nums[i]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    TreeNode* constructTree(vector<int> &nums,int start, int end){
        // get the maximum index
        if(start>end)   return nullptr;
        int maxiIdx = getMaxIndex(nums,start,end);
        TreeNode* root = new TreeNode(nums[maxiIdx]);

        root->left = constructTree(nums,start,maxiIdx-1);
        root->right = constructTree(nums,maxiIdx+1,end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums,0,nums.size()-1);
    }
};