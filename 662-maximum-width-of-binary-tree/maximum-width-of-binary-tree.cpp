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
    typedef long long ll;
        int widthOfBinaryTree(TreeNode* root) {

            if (root == nullptr)
            return 0;

              queue<pair<TreeNode*, ll>> q;
              ll ans = 0;
              q.push({root, 0});

              while (!q.empty()) {
                int size = q.size();
                ll firstIdx = q.front().second;
                ll lastIdx = q.back().second;

                ans = max(ans, lastIdx - firstIdx + 1);
                while(size--) {

                  TreeNode *node = q.front().first;
                  ll idx = q.front().second;
                  q.pop();

                  if (node->left) {
                    q.push({node->left, 2 * (idx - firstIdx) + 1});
                  }
                  if (node->right) {
                    q.push({node->right, 2 * (idx - firstIdx) + 2});
                  }
                }
              }

              return ans;

        
    }
};