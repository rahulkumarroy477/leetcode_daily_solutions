/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*> mp;
    void childToPar(TreeNode* root){
        if(!root)   return;

        if(root->left){
            mp[root->left] = root;
            childToPar(root->left);
        }
        if(root->right){
            mp[root->right] = root;
            childToPar(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(!root)   return {};
        childToPar(root);
        unordered_set<TreeNode*> vis;
        int c = 0;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);

        vector<int> ans;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(c == k)  ans.push_back(node->val);
                // left
                if(node->left && vis.find(node->left) == vis.end())
                {
                    vis.insert(node->left);
                    q.push(node->left);
                }
                // right
                if(node->right && vis.find(node->right) == vis.end())
                {
                    vis.insert(node->right);
                    q.push(node->right);
                }
                // parent
                if(mp[node] && vis.find(mp[node]) == vis.end()){
                    vis.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            c++;

            if(c>k) break;
        }

        return ans;

    }
};