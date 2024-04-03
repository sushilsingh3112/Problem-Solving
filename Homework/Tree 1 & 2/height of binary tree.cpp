#include<bits/stdc++.h>
using namespace std;
int heightOfBinaryTree(treeNode* root){
if(root==NULL){
        return 0;
    }
    int leftDepth=heightOfBinaryTree(root->left);
    int rightDepth=heightOfBinaryTree(root->right);
    
    int ans=max(leftDepth,rightDepth)+1;

    return ans;
}
