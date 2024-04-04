 bool getPath(TreeNode* A, int B,vector<int>&ans){
     if(A==NULL){
         return false;
     }
     ans.push_back(A->val);
     if(A->val==B){
         return true;
     }
     if(getPath(A->left,B,ans)|| getPath(A->right,B,ans)){
         return true;
     }
     ans.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL){
        return ans;
    }
    getPath(A,B,ans);
    return ans;
}
