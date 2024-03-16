#include<bits/stdc++.h>
using namespace std;

int check(int l,vector<int>& nums, int T)
{
    int i=0;
    int sum=0;
    while(i<l)
    {
        sum+=nums[i];
        i++;
    }
    int j=0;
    while(i<nums.size())
    {
        if(sum>T)
        return 0;
        sum-=nums[j];
        sum+=nums[i];
        i++;j++;
    }
    return 1;
}
int main()
{
    int target=0;
    cin>>target;
    vector<int>nums;
    int n=0;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int x; cin>>x;
        nums.push_back(x);
      
    }

    int s=1;
    int e=n;
    
    int ans=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int t=check(mid,nums,target);
        if(t==1)
        {
        s=mid+1;
        
        ans=mid;
        }
        else
        e=mid-1;
    }
    cout<<ans<<endl;




}
