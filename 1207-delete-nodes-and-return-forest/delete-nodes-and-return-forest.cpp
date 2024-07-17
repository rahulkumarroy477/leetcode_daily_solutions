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

unordered_map<TreeNode*,TreeNode*> mp;
void setMap(TreeNode* root){
    if(root == nullptr){
        return;
    }

    if(root->left){
        mp[root->left] = root;
        setMap(root->left);
    }
    if(root->right){
        mp[root->right] = root;
        setMap(root->right);
    }
}
void deleteNodes(TreeNode* root,unordered_set<int> &st){
    if(root == nullptr) return;
    TreeNode* left = root->left, *right = root->right;
    if(st.find(root->val)!=st.end()){
        TreeNode *parent = mp[root];
        // first update parent 
        if(parent->left && parent->left->val == root->val){
            parent->left = nullptr;
        }
        if(parent->right && parent->right->val == root->val){
            parent->right = nullptr;
        }

        // update child parent as themselves
        if(root->left){
            mp[left] = left;
        }
        if(root->right){
            mp[right] = right;
        }

        mp.erase(root);
    }

    deleteNodes(left,st);
    deleteNodes(right,st);
}
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& nums) {
        mp[root] = root;
        setMap(root);
        unordered_set<int>  st(nums.begin(),nums.end());

        deleteNodes(root,st);
        vector<TreeNode*> ans;
        for(auto it:mp){
            if(it.first == it.second)
                ans.push_back(it.first);
        }

        return ans;
    }
};