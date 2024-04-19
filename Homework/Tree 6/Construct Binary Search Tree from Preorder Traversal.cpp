class Solution {
public:
    TreeNode* Constructbst(vector<int>& preorder, int start, int end)
    {
        if(end<start)
        return NULL;

        TreeNode* root = new TreeNode(preorder[start]);
        int i = start+1;
        for(i = start+1;i<=end;i++)
        {
            if(preorder[i]>preorder[start])
            {
                break;
            }
        }
        root->left = Constructbst(preorder,start+1,i-1);
        root->right = Constructbst(preorder,i, end);

        return root;

    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int start = 0;
        int end = preorder.size()-1;
        
        return Constructbst(preorder,start,end);
        
    }
};
