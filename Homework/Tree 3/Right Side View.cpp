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
    cout<<"Enter the data "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;

    }

    Node*root=new Node(data);
    cout<<"Enter data for left part of"<<data<<"node"<<endl;
    root->left=buildTree();
        cout<<"Enter data for right part of"<<data<<"node"<<endl;
    root->right=buildTree();

    return root;

}

void PrintRightView( Node*root,vector<int> &ans,int level){
    if(root==NULL){
        return ;
        
    }
    if(level==ans.size()){
     ans.push_back(root->data);
    }
    PrintRightView(root->right,ans,level+1);
    PrintRightView(root->left,ans,level+1);

}
int main(){
     
     Node*root=buildTree();
     vector<int>ans;
     int level=0;
     PrintRightView(root,ans,level);
     cout<<"printing ans"<<endl;
     for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
     }


    return 0;
}
