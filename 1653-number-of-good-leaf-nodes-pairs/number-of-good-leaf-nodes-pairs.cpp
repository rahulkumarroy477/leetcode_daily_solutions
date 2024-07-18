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
unordered_set<TreeNode*> leafNodes;
unordered_map<TreeNode*,TreeNode*> mp;

void solve(TreeNode* root){
    if(root == nullptr) return;

    if(root->left == nullptr && root->right == nullptr){
        leafNodes.insert(root);
    }

    if(root->left){
        mp[root->left] = root;
        solve(root->left);
    }
    if(root->right){
        mp[root->right] = root;
        solve(root->right);
    }
}
public:
    int countPairs(TreeNode* root, int distance) {
        if(root == nullptr) return 0;

        mp[root] = nullptr;
        solve(root);
        int count = 0;
        for(auto &leaf:leafNodes){
            unordered_set<TreeNode*> visited;
            queue<TreeNode*> q;
            q.push(leaf);
            visited.insert(leaf);
            int currDist = 0;
            while(!q.empty() && currDist<distance){
                int size = q.size();
                currDist++;
                while(size--){
                    auto currNode = q.front();
                    q.pop();
                    vector<TreeNode*> adj = {currNode->left,currNode->right,mp[currNode]};
                    for(auto node:adj){
                        if(node!=nullptr && visited.find(node)==visited.end()){
                            if(leafNodes.find(node)!=leafNodes.end()) 
                                count++;
                            visited.insert(node);
                            q.push(node);
                        }
                    }

                }
            }

        } 

        return count/2;  

    }
};