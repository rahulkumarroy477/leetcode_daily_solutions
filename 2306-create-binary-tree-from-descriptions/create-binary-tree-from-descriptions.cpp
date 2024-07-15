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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<TreeNode*,TreeNode*>> mp;
        
        for(auto node:descriptions){

            int parent = node[0];
            int child = node[1];
            int isLeft = node[2];
            TreeNode *n=NULL;
            TreeNode *p=NULL;
            if(mp.find(parent)!=mp.end()){
                p=mp[parent].first;
            }
            else{
                p=new TreeNode(parent);
                mp[parent]={p,p};
            }
            if(mp.find(child)!=mp.end()){
                n=mp[child].first;
            }
            else{
                n=new TreeNode(child);
                mp[child]={n,n};
            }
            if(isLeft==1){
                p->left=n;
            }
            else{
                p->right=n;
            }
            mp[child].second=p;
    }
      for(auto it:mp){
            if(it.second.second == it.second.first)   return it.second.first;
        }
        return nullptr;
    }
};