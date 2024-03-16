#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) 
{
        int s=0;
        int e=nums.size()-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[s]<=nums[mid])
            {
               if(target>=nums[s] && target<nums[mid])
               {
                   e=mid-1;
               }
               else 
               s=mid+1;
            }
            else 
            {
                if(target>nums[mid] && target<=nums[e])
                {
                    s=mid+1;
                }
                else 
                e=mid-1;
            }
        }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int t;
    cin>>t;
    int ans=search(nums,t);
    cout<<ans<<endl;
}
