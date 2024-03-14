
#include<bits/stdc++.h>
using namespace std;

    int findMin(vector<int>& nums) {
        if(nums[0]<nums.back())
        return nums[0];
        int s=0;
        int e=nums.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0])
            {
                s=mid+1;
            }
            else
            e=mid;
        }
        return nums[e];
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
     int val= findMin(nums);
     cout<<val<<endl;
}
