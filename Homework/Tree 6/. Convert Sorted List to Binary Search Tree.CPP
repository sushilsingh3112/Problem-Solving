 TreeNode* ArrayToBST(vector<int> ans,int s,int e){
   
        if(s>e){
            return NULL;
        }

     int  mid=(s+e)/2;
           TreeNode*head=new TreeNode (ans[mid]);

             head->left=ArrayToBST(ans,s,mid-1);
            head->right= ArrayToBST(ans,mid+1,e);

            return head;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ans;
        ListNode* temp=head;
        while(temp!=NULL){
            
            ans.push_back(temp->val);
            temp=temp->next;

        }
        int s=0;
        int e=ans.size()-1;
        return ArrayToBST( ans,s,e);
       
    }
