#include<bits/stdc++.h>
using namespace std;
class Node{
   public:

   int data;
   Node*left;
   Node*right;

   Node(int data){
    this->data=data;
    left=NULL;
    right=NULL;

   }


};



Node*buildTree(){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    } 
    //step A= create a node
    Node*root=new Node(data);
    cout<<"Enter data for left part of data"<<data<<"node"<<endl;
    //step B move left part
    root->left=buildTree();
    cout<<"Enter data for right part of "<<data<<"node"<<endl;
    root->right=buildTree();
    return root;
    
}
void PrintLeftView(Node*root,vector<int>&ans,int level){
   if(root==NULL){
    return;

   }
   if(level==ans.size()){
    ans.push_back(root->data);
   }

   PrintLeftView(root->left,ans,level+1);
   PrintLeftView(root->right,ans,level+1);


}


int main(){
Node*root=buildTree();
vector<int>ans;
int level=0;
PrintLeftView(root,ans,level);
cout<<"Printing the left view"<<endl;
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}




    return 0;
}
