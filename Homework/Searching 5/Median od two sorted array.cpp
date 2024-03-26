class Solution {
public:
 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m=nums1.size();
        int n=nums2.size();
        if(n<m)
        return findMedianSortedArrays(nums2,nums1);
        int s=0;
        int e=m;
        while(s<=e)
        {
            int i1=(s+e)/2;
            int i2=(n+m+1)/2 -i1;
            int max1= (i1==0)? INT_MIN :nums1[i1-1];
            int min1= (i1==m)? INT_MAX : nums1[i1];
            int max2=(i2==0) ? INT_MIN : nums2[i2-1];
            int min2 = (i2==n)? INT_MAX : nums2[i2];
            if(max2<=min1 && max1<=min2)
            {
                if((n+m)%2==0)
                {
                    return max(max1,max2)+min(min1,min2)/2.0;
                }
                else 
                return  max(max1,max2);
            }
            else if(max1>min2)
            {
                e=i1-1;
            }
            else 
            s=i1+1;
        }
        return 0.0;
    }
};
