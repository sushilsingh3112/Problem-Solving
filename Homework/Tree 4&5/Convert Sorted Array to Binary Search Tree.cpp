TreeNode*SortedAbst(vector<int>&nums,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=SortedAbst(nums,start,mid-1);
    root->right=SortedAbst(nums,mid+1,end);

   return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
       return SortedAbst(nums,start,end);
        //return root;
    }
