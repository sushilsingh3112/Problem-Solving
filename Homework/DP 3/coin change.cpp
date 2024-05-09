class Solution {
    // int solve(vector<int>&coins,int amount){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(amount<0){
    //         return INT_MAX;
    //     }
    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         int ans=solve(coins,amount-coins[i]);
    //         if(ans!=INT_MAX){
    //             mini=min(mini,1+ans);
    //         }
    //     }
    //     return mini;
    // }
    int solvedp(vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
           int ans=solvedp(coins,amount-coins[i],dp);
          if(ans!=INT_MAX){
            mini=min(mini,1+ans);
           }
        }
        dp[amount]=mini;
        return  mini;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solvedp(coins,amount,dp);
        if(ans==INT_MAX)
            return -1;
        else
            return ans; 
    }
};
