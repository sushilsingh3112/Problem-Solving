#include<bits/stdc++.h>
using namespace std;

bool solve(TreeNode*root,int targetSum,int sum){
    if(root==NULL){
        return false;
    }
    sum=sum+root->val;
    if(root->left==NULL&&root->right==NULL){
        if(sum==targetSum)
        return true;
    }
    return solve(root->left,targetSum,sum)||solve(root->right,targetSum,sum);
    sum=sum-root->val;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return solve(root,targetSum,sum);
    }
