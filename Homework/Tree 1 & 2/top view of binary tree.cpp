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

    //step ABC
    Node*root=new Node(data);
    cout<<"Enter data for left part of"<<data<<"node"<<endl;
    root->left=buildTree();
        cout<<"Enter data for right part of"<<data<<"node"<<endl;
    root->right=buildTree();

    return root;
}

//    void levelOrderTraversal(Node*root){
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node*temp=q.front();
//         q.pop();
//         cout<<temp->data <<" ";
//         if(temp->left){
//             q.push(temp->left);
//         }
//         if(temp->right){
//             q.push(temp->right);
//         }

//     }
//    }
void PrintTopView(Node*root){
    if(root==NULL){
        return;
 
    }
    map<int,int>topNode;
    queue<pair<Node*,int>>q;

    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int>temp=q.front();
        q.pop();
        Node*frontNode=temp.first;
        int hd=temp.second;
        if(topNode.find(hd)==topNode.end()){
            topNode[hd]=frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
        cout<<"printing"<<endl;
        for(auto i:topNode)
        cout<<i.first<<" ->" <<i.second<<endl;
    }
}


int main(){


 Node*root=NULL;
 root=buildTree();


    // levelOrderTraversal(root);

    PrintTopView(root);
    

}
