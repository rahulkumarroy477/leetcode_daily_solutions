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
    vector<vector<int>> ans;
    vector<int> temp;
    void trav(TreeNode* root)
    {
        if(root==NULL)  return;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        trav(root->left);
        trav(root->right);
        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        trav(root);
        int sum = 0;
        for(int i =0;i<ans.size();i++)
        {
            int tempSum =0;
            for(int j= 0;j<ans[i].size();j++)
            {
                tempSum = tempSum*10+ans[i][j]; 
            }
            sum= sum + tempSum;
        }
        return sum;
    }
};