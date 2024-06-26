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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        
        stack<TreeNode*> st;
        
        while(true){
            if(root != nullptr){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty())  break;
                
                ans.push_back(st.top()->val);
                root = st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};