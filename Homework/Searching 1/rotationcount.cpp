#include<bits/stdc++.h>
using namespace std;
int findKRotation(int arr[], int n) {
	    // code here
	    if(arr[0] <arr[n-1])
	    return 0;
	    int s=0;
	    int e=n-1;
	    while(s<e)
	    {
	        int mid=s+(e-s)/2;
	        if(arr[mid]>=arr[0])
	        s=mid+1;
	        else
	        e=mid;
	    }
	    return s;
	}
