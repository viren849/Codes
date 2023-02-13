

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

   vector<int>lis;
   int ins[n];

   for(int i=0;i<n;i++)
   {
        if(lis.empty() || lis.back() < arr[i])
          {
            lis.pb(arr[i]);
            ins[i]=lis.size();
          }
          else 
          {
             auto it =lower_bound(lis.begin(),lis.end(),arr[i]);
             *it=arr[i];
             ins[i]=it-lis.begin()+1;
          }
   }

   int len=lis.size();

   cout<<len<<":"<<endl;

   vector<int>final;

   for(int i=n-1;i>=0;i--)
   {
        if(ins[i]==len)
        {
          final.pb(arr[i]);
          len--;
        }
   }
   
   reverse(final.begin(),final.end());
   
   for(auto i : final)
    cout<<i<<" ";
}

signed main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
  //cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}