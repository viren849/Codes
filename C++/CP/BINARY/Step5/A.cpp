#include<bits/stdc++.h>
using namespace std;

#define ld              long double
#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

ll n,k;
vector<pair<ll,ll>>vp;

bool good(ll m )
{
  ll s=0;
    for(int i=0;i<n;i++)
      if(vp[i].first > m)
        s+=0;
      else
        s+=min(m-vp[i].first , vp[i].second - vp[i].first+1);
      return s<=k;
}
void solve()
{ 
  cin>>n>>k;
  vp.resize(n); 
  
    ll l=INT_MAX;
    ll r=INT_MIN;
  for(int i=0;i<n;i++)
    {
      cin>>vp[i].first>>vp[i].second;
      l=min(l,vp[i].first);
      r=max(r,vp[i].second);
    }

    ll ans=0;
    

   while(l<=r)
   {
      ll m=(l+r)>>1;
      
      if(good(m))
      {
        ans=m;
        l=m+1;
      }
      else r=m-1;
   }
   cout<<ans;
}

int main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
  // cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}