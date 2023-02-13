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
  int x,n;
  cin>>x>>n;
  
   set<int>pos={0,x};
   multiset<int>dist{x};
   
   for(int i=0;i<n;i++)
   {
    int p;
    cin>>p;

    auto it1=pos.upper_bound(p);
    auto it2=it1;
    it2--;

    dist.erase(dist.find(*it1-*it2));
    dist.insert(p-*it2);
    dist.insert(*it1-p);
    pos.insert(p);

    auto ans=dist.end();
    ans--;
    cout<<*ans<<" ";
   }
}