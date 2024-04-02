#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

};

Node* buildTree(){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    cout<<"Enter the left part of thr data"<<data<<" node"<<endl;
    root->left= buildTree();
     cout<<"Enter the right part of thr data "<<data<<" node"<<endl;
    root->right=buildTree();

    return root;
}


  void levelOrder(Node *root,int level,int &oddsum, int &evensum){
      if(root==NULL){
          return;
      }
      if(level%2==0){
          evensum+=root->data;
      }
      if(level%2!=0){
          oddsum+=root->data;
      }
      levelOrder(root->left,level+1,oddsum,evensum);
      levelOrder(root->right,level+1,oddsum,evensum);
  }

    int getLevelDiff(Node *root)
    {
       int oddsum=0;
       int evensum=0;
       int level=1;
       levelOrder(root,level,oddsum,evensum);
       
       return (oddsum-evensum);
    }


int main(){

    Node* root;
    root=buildTree();
    int ans=getLevelDiff(root);
    cout<<ans;

    return 0;
}
