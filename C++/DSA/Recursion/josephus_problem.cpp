#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(int k,int ind,vector<int>&v)
{
    if(v.size()==1)
    {
      cout<<v[0];
      return ;
    }
    int kill = (ind + k ) % v.size();

    cout<<v[kill]<<" ";
    
    v.erase(v.begin()+kill);
    solve(k,kill,v);
}
signed main(){
  fast;
  int n;
  cin>>n;
  
  int k=2;
  k--;

  vector<int>v;

  for(int i=1;i<=n;i++)
    v.pb(i);

  solve(k,0,v);
}