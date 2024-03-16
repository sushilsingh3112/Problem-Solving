#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int>a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    while(q--)
    {
        int h;
        cin>>h;
        sort(a.begin(),a.end());
        
        auto index = lower_bound(a.begin(), a.end(), h)-a.begin();
        cout<<n-index<<endl;
    }

    return 0;
}
