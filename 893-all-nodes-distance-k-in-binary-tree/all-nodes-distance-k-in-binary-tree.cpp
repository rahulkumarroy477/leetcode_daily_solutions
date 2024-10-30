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

    // child to parent mapping
    unordered_map<TreeNode*, TreeNode*> mp;

    void traversal(TreeNode* root){
        if(root == NULL) return;

        if(root->left) mp[root->left] = root;
        traversal(root->left);
        if(root->right) mp[root->right] = root;
        traversal(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traversal(root);
        vector<int> ans;

        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            // If we've reached the desired distance k, collect nodes and stop further processing
            if (count == k) {
                for (int i = 0; i < size; ++i) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }

            for(int i = 0;i<size;i++){
                auto node = q.front();
                q.pop();

                if(node->left && vis.find(node->left) == vis.end()){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && vis.find(node->right) == vis.end()){
                    q.push(node->right);
                    vis.insert(node->right);
                }

                if(mp.find(node) != mp.end() and vis.find(mp[node]) == vis.end()){
                    q.push(mp[node]);
                    vis.insert(mp[node]);
                }
            }

            count++;
        }

        return ans;
    }
};

