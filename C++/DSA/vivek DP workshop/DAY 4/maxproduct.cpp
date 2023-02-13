

#include<bits/stdc++.h>
using namespace std;

#define int              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 


void solve()
{
      int n;
      cin>>n;
      int arr[n];

      for(int i=0;i<n;i++)
        cin>>arr[i];

      int mx=1;
      int mn=1;

      int t;
      int ans=LLONG_MIN;

      for(int i=0;i<n;i++)
      {
        t=mn;
        mn=min({arr[i],mn*arr[i],mx*arr[i]});
        mx=max({arr[i],mx*arr[i],t*arr[i]});
        ans=max(ans,mx);

      }
      cout<<ans;
}
signed main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}