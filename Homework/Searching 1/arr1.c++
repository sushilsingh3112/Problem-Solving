#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6};
    int size=6;
    int key=1;
    bool flag=0;
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            flag=1;
        break;
        }
        else{
            flag=0;
        }
    }
    if (flag)
    cout<<"present"<<endl;
    else
    cout<<"absent"<<endl;
    return 0;
}