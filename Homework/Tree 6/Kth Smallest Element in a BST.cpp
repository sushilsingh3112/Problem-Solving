 int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL){
            return -1;
        }
        //inorder
            //left
        int leftAns=kthSmallest(root->left,k);

             if(leftAns!=-1)
              return leftAns;

           k--;
           //current node
           if(k==0){
            return root->val;
           }
            //right
             int rightAns=kthSmallest(root->right,k);
             return rightAns;
    }
