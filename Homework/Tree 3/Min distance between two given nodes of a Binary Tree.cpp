  Node*LCA(Node*root,int a,int b){
        if(root==NULL || root->data==a || root->data==b){
              return root;
           }
        Node*left=LCA(root->left,a,b);
        Node*right=LCA(root->right,a,b);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
    
    bool findpath(Node*root,int k,vector<int> &arr){
        if(root==NULL){
            return false;
        }
     arr.push_back(root->data);
        
     if(root->data==k){
            return true;
        }
      if(findpath(root->left,k,arr) || findpath(root->right,k,arr)){
            return true;
        }
     arr.pop_back();
     return false;
       }
    
     int findD(Node*root,int k,int dist){
       vector<int> arr;
     findpath(root,k,arr);
     dist=arr.size()-1;
       return dist;
        
      }
        int findDist(Node* root, int a, int b) {
        // Your code here
        Node*lca = LCA(root,a,b);
        int d1=findD(lca,a,0);
        int d2=findD(lca,b,0);
        return d1+d2;
     }
