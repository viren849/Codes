#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


signed main(){

  int n,m; 
  cin>>n>>m;
  
  int arr[n];
 
  unordered_map<int,int>mp;

  for(int i=0;i<n;i++)
      cin>>arr[i],mp[arr[i]]=i;
  
  int sum=1;
  for(int i=0;i<n;i++)
     {
          if(arr[i] > 1 and mp[arr[i]] < mp[arr[i]-1]) sum++;
     }

  while(m--)
  {
    set<pair<int,int>>st;
    int a,b;
    cin>>a>>b;

    int x=a-1;
    int y=b-1;

    a=arr[x];
    b=arr[y];

    if(a > 1)
    st.insert({a-1,a});
    if(a<n)
    st.insert({a,a+1});
    if(b > 1)
      st.insert({b-1,b});
    if(b<n)
      st.insert({b,b+1});
    
    for(auto it : st)
    {
      sum-=(mp[it.F]>mp[it.S]);
    }

    
    swap(arr[x],arr[y]);
    swap(mp[a],mp[b]);

    for(auto it : st)
    {
      sum+=(mp[it.F]>mp[it.S]);
    }
      cout<<sum<<endl;
      st.clear();
    // for(auto it : mp)
    //   cout<<it.first<<"->"<<it.second<<endl;
    // for(int i=0;i<n;i++)
    //   cout<<arr[i]<<" ";
    // cout<<endl<<endl; 
  }
}