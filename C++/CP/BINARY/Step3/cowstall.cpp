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

bool good(ll m)
{
  if(v[n-1] - v[0] < m)
    return 0;
  int cow=1;
  ll pos=v[0];
  for(int i=1;i<n;i++)
  {
       if(v[i] - pos >= m)
       {
          pos=v[i];
          cow++;
       }
  }
  return cow >= k ;
}

void solve()
{ 
	cin>>n>>k;
  v.resize(n);	

  for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }

  ll l=0,r=v[n-1]-v[0];
  ll ans=0;

  while(l<=r)
  {
    ll m=(l+r)/2;
    if(good(m))
    {
      ans=m;
      l=m+1;
    }
    else
      r=m-1;
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