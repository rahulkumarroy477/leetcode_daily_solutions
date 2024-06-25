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
class CBTInserter {
public:
    TreeNode* parent;
    queue<TreeNode*> q;
    CBTInserter(TreeNode* root) {
        
        this->parent = root;
        if(root!=nullptr){
            q.push(root);
            while(!q.empty()){
                TreeNode* node = q.front();
                
                if(node->left != nullptr)   q.push(node->left);
                if(node->right != nullptr)  q.push(node->right);
                // whether current node has both nodes then don't update the next insertion point
                if (!(node->left && node->right)) break;
                q.pop();
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* node = q.front();
        if(!node->left) node->left = newNode;
        else{
            node->right = newNode;
            q.pop();
        }

        q.push(newNode);
        return node->val;
    }
    
    TreeNode* get_root() {
        return parent;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */