#include<bits/stdc++.h>
using namespace std;

#define ld 				      long double
#define ll              long long int 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int n,k;
vector<int>v;
ll s=0;

bool good(ll m)
{
  ll tmpsum=0;
  int seg=1;
  for(int i=0;i<n;i++)
  {
    if(v[i] > m)
      return 0;
    if(tmpsum + v[i] <= m)
      tmpsum+=v[i];
    else
    {
      tmpsum=v[i];
      seg++;
    }
    if(seg > k)return 0;
  }
  return seg<=k;
}
void solve()
{ 
	cin>>n>>k;
  v.resize(n);	

  for(int i=0;i<n;i++)
    {
      cin>>v[i];
      s+=v[i];
    }

  ll l=0,r=s;
  ll ans=0;

  while(l<=r)
  {
    ll m=(l+r)/2;
    if(good(m))
    {
      ans=m;
      r=m-1;
    }
    else
      l=m+1;
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