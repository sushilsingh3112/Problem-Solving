#include <bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    vector<int> ans;
    int i = 0;
     while(i<n){
      ans.push_back(arr1[i]);
        i++;
     }
       i = 0; 
       while(i<m){
      ans.push_back(arr2[i]);
        i++;
       }
    sort(ans.begin(), ans.end());
    return ans[k-1];
 }
