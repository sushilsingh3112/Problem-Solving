

bool solve(TreeNode *root,long mini,long maxi){

    if(root==NULL){
        return true;
    }
    if(root->val<=mini||root->val>=maxi){
        return false;
    }
    return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
            return true;
}
    bool isValidBST(TreeNode* root) {

        long mini =     LONG_MIN;
        long maxi = LONG_MAX;
        return solve(root,mini,maxi); 
        
    }
