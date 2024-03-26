int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int height=max(maxDepth(root->left),maxDepth(root->right));
        return height+1;
        
    }
