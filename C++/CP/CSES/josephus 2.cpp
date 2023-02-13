#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int             int
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


signed main(){
  fast;
  int n,k;
  cin>>n>>k;
  
  ordered_set st;

  for(int i=1;i<=n;i++)
    st.insert(i);
  
  int ind=0;
  while(st.size() > 0)
  { 
    ind%=st.size();
    int kill=(ind+k)%st.size();
    ind=kill;
    auto it = st.find_by_order(kill);
    cout<<*it<<" ";
    st.erase(it);
  }
}