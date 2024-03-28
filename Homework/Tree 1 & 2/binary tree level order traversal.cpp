//#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
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
    cout<<"Enter the data->"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new TreeNode(data);
    cout<<"Enter the left part of thr data:-> "<<data<<" node"<<endl;
    root->left= buildTree();
     cout<<"Enter the right part of thr data:-> "<<data<<" node"<<endl;
    root->right=buildTree();

    return root;
}

void solve(TreeNode* root,int level, map<int,vector<int>> &mp){
    if(root==NULL){
        return;
    }
    mp[level].push_back(root->data);
    solve(root->left ,level+1,mp);
    solve(root->right ,level+1,mp);
}

void levelOrder(TreeNode* root, vector<vector<int>> &ans) {    
    map<int,vector<int>> mp;
    if(root==NULL){
        return;
    }
    int level=0;
    solve(root,level,mp);
    for(auto it:mp){
        ans.push_back(it.second);
    }
}

int main(){

    Node * root;
    root=buildTree();
    vector<vector<int>> ans;
    levelOrder(root,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}
