#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &arr, int n, int m){
        // code here       
        int l=1e8,h=-1e8;
        for(int i=0;i<n;i++){
            l=min(l,arr[i][0]);// min
            h=max(h,arr[i][m-1]);// max
        }
        int median_ind=(n*m)/2;// midle index

      while(l<=h){
          int mid=l+(h-l)/2;
          int cnt=0;
          for(int i=0;i<n;i++){// find no of element smaller then mid for every row
              int ub= upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();//upper bound
              cnt+=ub;
          }
          if(cnt>median_ind){// if greater then shrink h
              h=mid-1;
          }
          else{
              l=mid+1;
          }
      }
      return l;
    }
