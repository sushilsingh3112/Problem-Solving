

 void printLeftBoundry(TreeNode<int>*root,vector<int>&ar){
  if(root==NULL){
    return ;
  }
  if(root->left==NULL&&root->right==NULL)
          return;
    ar.push_back(root->data);
       // return;
    if(root->left){
        printLeftBoundry(root->left,ar);
    }
    else{
        printLeftBoundry(root->right,ar);
    }
  }

  void printLeafBoundry(TreeNode<int>*root,vector<int>&ar){
       if(root==NULL){
        return;
       }
      if(root->left==NULL&&root->right==NULL)
     
     ar.push_back(root->data);
        
        printLeafBoundry(root->left,ar);
        printLeafBoundry(root->right,ar);
    }
  

  void printRightBoundry(TreeNode<int>*root ,vector<int>&ar){
       if(root==NULL){
        return ;
       }
      if(root->left==NULL&&root->right==NULL){
        return;
      }
      if(root->right){
        printRightBoundry(root->right,ar);
      }
      else
        printRightBoundry(root->left,ar);
      
      ar.push_back(root->data);
    }
 

  


vector<int> traverseBoundary(TreeNode<int> *root)
{
      vector<int>ar;
	// Write your code here.
    if(root==NULL){
        return ar;
    }

    ar.push_back(root->data);
    printLeftBoundry(root->left,ar);
    printLeafBoundry(root,ar);
  //  printLeafBoundry(root->right,ar);
    printRightBoundry(root->right,ar);
    return ar;
}
