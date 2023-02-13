#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
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

    int mn=arr[0];
    int i=0;
    int ans=INT_MIN;
    for(int a=0;a<n;a++)
      {
          if( mn < arr[a])
            ans=max(ans,arr[a]-mn);
          
            mn=min(mn,arr[a]);
            i=a;
          
      }
      cout<<ans;
}

int main()
{
    
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}