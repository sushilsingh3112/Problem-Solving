#include<bits/stdc++.h>
using namespace std;

void CheckNode(TreeNode*root,vector<string>&s,string path){
            if(root==NULL){
            return;
            }
           path=path+to_string(root->val)+"->";
          if(root->left==NULL&&root->right==NULL){
           s.push_back(path.substr(0,path.length()-2));
           return; 
           }
          CheckNode(root->left,s,path);
          CheckNode(root->right,s,path);
       }
          
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        string str="";
        CheckNode(root,s,str);
        return s;
        

    }
