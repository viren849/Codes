#include<bits/stdc++.h>
using namespace std;

#define ld              long double
#define ll              long long int 
#define pb              push_back
#define F               first
#define S               second 


void solve()
{
     
     int n,m;
     cin>>n>>m;
     
    cout<<n/m+n%m;
}

int main()
{
  
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);

  int t=1;
   cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}