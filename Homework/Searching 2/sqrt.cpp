#include <iostream>
#include <vector>
using namespace std;

int sqrt( int x){
    if(x==1){
            return 1;
        }
        if(x==0){
            return 0;
        }
        long int start=1;
        long int end=x/2;
        long int mid;
        long int ans=0;
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid*mid==x){
                return mid;
            }
            
            else if(mid*mid<x){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    return ans;
}


int main()
{

    long int n=8;
    int ans=sqrt(n);
    cout<<ans;
    return 0;
}
