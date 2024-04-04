void NodeSum(TreeNode*root,int low,int high,vector<int> &ans){

if(root==NULL){
    return ;
}
if(root->val>=low&&root->val<=high){
    ans.push_back(root->val);
}
NodeSum(root->left,low,high,ans);
NodeSum(root->right,low,high,ans);

}
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
           int sum=0;
       NodeSum(root,low,high,ans);
       
       for(int i=0;i<ans.size();i++){
           sum=sum+ans[i];
       }
       return sum;
    }
