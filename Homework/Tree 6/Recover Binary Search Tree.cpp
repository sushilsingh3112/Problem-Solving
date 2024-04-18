class Solution {
private: 
    void solve(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root){
            return;
        }
 solve(root->left, prev, first, end);
        if (prev) {
            if (root->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                end = root;
            }
        }

        prev = root;
         solve(root->right, prev, first, end);
    }
    
    public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        solve(root, prev, first, end);
        swap(first->val, end->val);
        return;
    }
};
