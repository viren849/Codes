
//Candy Distribution Problem .....
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

void solve(){
    
    int n;
    cin>>n;

    vector<int>v;

    for(int i=0;i<n;i++){int x;cin>>x;v.pb(x);}

    vector<int> can(n,1);

    int ans=0;

    for(int i=1;i<n;i++)
      if(v[i] > v[i-1])can[i]=can[i-1]+1;
    for(int i=n-2;i>=0;i--)
      if(v[i]>v[i+1])can[i]=max(can[i+1]+1,can[i]);

    for(int i=0;i<n;i++)
          ans+=can[i];
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