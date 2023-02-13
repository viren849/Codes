#include<bits/stdc++.h>
using namespace std;

#define int            long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,k;
int a[100001];
int b[100001];

int count(int md)
{
  int i=0,j=n-1;
  int cnt=0;

  while(i<n && j >=0)
  {
    if(a[i]+b[j] >= md)
    {
       j--;
    }
    else
    {
      i++;
      cnt+=(j+1);
      cout<<cnt<<" ";
    }
  }
  cout<<endl;
  return cnt;

}
void solve()
{
   cin>>n>>k;
   
   int mx=INT_MIN;
   int mx2=INT_MIN;

   for(int i=0;i<n;i++)
    {
      cin>>a[i];
      mx=max(mx,a[i]);
    }
  for(int i=0;i<n;i++)
    {
      cin>>b[i];
      mx2=max(mx2,b[i]);
    }
  
  sort(a,a+n);
  sort(b,b+n);

   int l=0;
   int r=mx+mx2;
   
   int ans=0;
   while(l<=r)
   {
      int md=(l+r)/2;

      if(count(md)<k)
      {
        ans=md;
        l=md+1;
      }
      else r=md-1;
   }
   cout<<ans<<" ";
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