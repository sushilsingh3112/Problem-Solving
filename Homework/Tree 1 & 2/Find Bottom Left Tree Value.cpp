
        vector<vector<int >> LevelOrderTrav(TreeNode * root){
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int s =q.size();
              vector<int>level; 
            for(int i=0;i<s;i++){
                
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                   q.push(temp->left);
                }
                 if(temp->right!=NULL){
                   q.push(temp->right);
                }
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        return ans;
        }
        int findBottomLeftValue(TreeNode* root) {
        
        vector<vector<int>>v=LevelOrderTrav(root);
        return v[v.size()-1][0];
    }
