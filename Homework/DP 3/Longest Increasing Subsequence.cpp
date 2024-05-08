/*Apporach 1-USING Recursion get TLE;
class Solution {
public:
     int solvelis(int prev, int i, vector<int>&nums)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        int take = 0;
        int nontake;
        if (prev== -1 or nums[prev] < nums[i])
        {
            take = 1 + solvelis(i, i + 1, nums);
        }
        
        nontake = solvelis(prev, i + 1, nums);
        return max(take, nontake);
    }
      int lengthOfLIS(vector<int>& nums)
    {
        return solvelis(-1,0, nums);
    }
};*/  


/*Approach-2 (TopDown: Recur+Memo) 
//T.C : O(n*n)
class Solution {
public:
    int n;
    int dp[2501][2501];
    int lis(vector<int>& nums, int prev, int curr) {
       if(curr == n)
           return 0;
        
        if(prev != -1 && dp[prev][curr] != -1)
            return dp[prev][curr];
        
        int taken = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            taken = 1 + lis(nums, curr, curr+1);
        
        int nottaken = lis(nums, prev, curr+1);
        
        if(prev != -1)
            dp[prev][curr] =  max(taken, nottaken);
        
        return max(taken, nottaken);
            
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();
        return lis(nums, -1, 0);
    }
};*/


 /*Approach-3 (Bottom Up)
//T.C : O(n^2) 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); 
        int maxLIS = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) 
                {
                dp[i] = max(dp[i], dp[j] + 1); 
                maxLIS = max(maxLIS, dp[i]); 
                }
            }
        }

        return maxLIS;
    }
};*/


//Approacj-4( BS (O(nlogn))
//T.C : O(nlogn)
//S.C : O(n)
 class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        for (int i = 0; i < n; i++) {
            int index = binarySearch(sorted, nums[i]);
            if (index == sorted.size())
            sorted.push_back(nums[i]);
            else
            sorted[index] = nums[i];
        }
        return sorted.size();
    }
   private:
    int binarySearch(vector<int>& sorted, int target) {
        int left = 0, right = sorted.size() - 1;
        int result = sorted.size();
        while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] < target) {
             left = mid + 1;
            } 
            else {
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }

};    
