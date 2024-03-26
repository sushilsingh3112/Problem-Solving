#include<bits/stdc++.h>
using namespace std;
    int minDays(vector<int>& nums, int m, int k) {
        int maxm=*max_element(nums.begin(),nums.end());
        
        int s=1;
        int e=maxm;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            long long count=0;
       
             long long t=0;
            for(int i=0;i<nums.size();i++)
            {
               
                if(nums[i]<=mid)
                {
                   count++;
                   if(count==k)
                   {
                       t++;
                       count=0;
                   }
                }
                else count=0;
            }
         
            if(t>=m)
            {
                
                ans=mid;
                e=mid-1;
            }
            else 
            s=mid+1;
        }
        return ans;
    }
};
