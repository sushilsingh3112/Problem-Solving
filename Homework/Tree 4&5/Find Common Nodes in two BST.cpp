class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
   void inorder(struct Node *root,vector<int> &v){
    if(root==NULL)
    return ;
    
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
        vector<int> v1,v2,ans;
     if(root1==NULL || root2==NULL) return ans;
     
     inorder(root1,v1);
     inorder(root2,v2);
     
     int i=0,j=0;
     while(i<v1.size() && j<v2.size()){
         if(v1[i]==v2[j]) {
             ans.push_back(v1[i]);
             i++;
             j++;
         }
         
         else if(v1[i]>v2[j]) j++;
         else i++;
     }
     return ans;
     
    }
     
    
};
