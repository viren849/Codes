#include<bits/stdc++.h>
using namespace std;

#define ld 				      long double
#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 


ll n,k;
vector<pair<int,int>>vp;

bool good(ll m )
{
    //cout<<m<<" ";
     ll s=0;
     for(ll i=1;i<=n;i++)
     {
         if(m < i)break;
         if(m%i == 0)s+=min(n,m/i-1);
         else s+=min(n,m/i);
     }
   //  cout<<endl;
     return s < k;
}
void solve()
{ 
  cin>>n>>k;

  ll l=1,r=n*n+10;
  ll ans=0;

  while(l<=r)
  {
    ll m = (l+r)>>1;

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