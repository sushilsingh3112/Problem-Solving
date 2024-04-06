bool ispossible(vector<int> &boards, int k, int n, long long int mid){

    long long int days=0;
    long long int painter=1;
    for(int i=0;i<n;i++){
        if(days+boards[i]<=mid){
            days+=boards[i];
        }
        else{
            painter++;
            if(painter>k || boards[i]>mid){
                return false;
            }
            days= boards[i];
        }

    }
    return true;
}

 

int findLargestMinDistance(vector<int> &boards, int k)
{

   long long int s=0;
   long long int sum=0;
   long long int n= boards.size();
   for(int i=0;i<n;i++){
       sum+=boards[i];
   }
   long long int e=sum;
   long long int ans=-1;
   long long int mid=s +(e-s)/2;
   while(s<=e){
       if(ispossible(boards,k,n,mid)){
           ans=mid;
           e=mid-1;
       }
       else{
           s=mid+1;
       }
       mid=s +(e-s)/2;
   }

 

   return ans;

}
