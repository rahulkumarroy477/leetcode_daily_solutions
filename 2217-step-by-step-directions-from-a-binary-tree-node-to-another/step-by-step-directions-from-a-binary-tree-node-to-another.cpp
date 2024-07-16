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
TreeNode* lowestCommonAncestor(TreeNode* root, int a, int b){
    if(root == NULL || root->val == a || root->val == b){
        return root;
    }

    TreeNode* leftLca = lowestCommonAncestor(root->left,a,b);
    TreeNode* rightLca = lowestCommonAncestor(root->right,a,b);

    if(leftLca == NULL) return rightLca;
    else if(rightLca == NULL)   return leftLca;
    else return root;
}


bool path(TreeNode* root,string &dir,int val){
    if(root == nullptr) return false;

    if(root->val == val)    return true;
    dir.push_back('L');
    if(path(root->left,dir,val))    return true;
    dir.pop_back();
    dir.push_back('R');
    if(path(root->right,dir,val))   return true;

    dir.pop_back();
    return false;
}

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root,startValue,destValue);
        
        string lcaToStart = "";
        path(lca,lcaToStart,startValue);

        string lcaToEnd = "";
        path(lca,lcaToEnd,destValue);

        cout<<lcaToStart<<" "<<lcaToEnd<<endl;

        string ans(lcaToStart.length(), 'U');
        ans.append(lcaToEnd);
        return ans;
    }
};