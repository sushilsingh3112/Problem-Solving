#include<bits/stdc++.h>
using namespace std;

TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        TreeNode *temp =root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(temp);
        return root;
    }
