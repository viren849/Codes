#include<bits/stdc++.h>
using namespace std;

#define int             long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,k;
int a[51];

bool check(int md)
{
     int sum=0;
     
     for(int i=0;i<n;i++)
     {
         if(a[i]  > md)sum+=md;
         else sum+=a[i];
     }
     return (sum/md)>=k;
}
void solve()
{
   cin>>k>>n;
   int s=0;
   for(int i=0;i<n;i++)
    {
      cin>>a[i];
      s+=a[i];
    }
  
  sort(a,a+n);

  int  l=0,r=s;

  int ans=1;
  while(l<=r)
  {
    int md=(l+r)/2;

    if(check(md))
    {
      ans=md;
      l=md+1;
    }
    else r=md-1;
  }
  cout<<ans;
}

signed main()
{
  fast;
  int t=1;
  //cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}