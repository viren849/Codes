#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


signed main(){
  fast;
  int n;
  cin>>n;
  
  int k=2;
  k--;
  vector<int>v;

  for(int i=1;i<=n;i++)
    v.pb(i);
   
   while(v.size()>1)
   {

    vector<int>sur;
    for(int i=0;i<v.size();i++)
    {
      if(i%2==0)
        sur.pb(v[i]);
      else cout<<v[i]<<" ";
    }
    
    if(v.size()%2 == 0)
      v=sur;
    else
    {
      int ls=sur.back();
      sur.pop_back();
      v.clear();
      v.pb(ls);
      for(int i : sur)
        v.pb(i);
    }
   }
   cout<<v[0];
  }