class TrieNode{
    public:
    int bit;
    TrieNode* binary[2];

    TrieNode(int bit){
        this->bit=bit;
        for(int i=0;i<2;i++){
            this->binary[i]=NULL;
        }
    }
};

class Solution {
    TrieNode* root;

    //insert
    void insertNumber(TrieNode* root,int num){
        
        TrieNode* node = root;

        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(node->binary[bit] == NULL){ 
                node->binary[bit] = new TrieNode(bit);
            }

            node = node->binary[bit]; 
        }
    }

    //xorr
    int xorOperation(TrieNode* root, int num){
        TrieNode* node=root;
        int max=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)& 1;

            int flip=1-bit;
            if(node->binary[flip]!=NULL){
                max=max|(1<<i);
                node=node->binary[flip];
            }
            else{
                node=node->binary[bit];
            }
        }
        return max;
    }

public:

    Solution(){
        root=new TrieNode(0);
    }

    int findMaximumXOR(vector<int>& nums) {
        int maxi=0;
        for(auto it: nums){
            insertNumber(root,it);
        }

        for(int i=1;i<nums.size();i++){
            int ans =xorOperation(root,nums[i]);
            maxi=max(maxi,ans);
        }

        return maxi;
    }
};
