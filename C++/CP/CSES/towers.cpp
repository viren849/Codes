#include<bits/stdc++.h>
using namespace std;

#define int             long long int
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


signed main(){

  int n; 
  cin>>n;
  
  int arr[n];
 
  vector<int>v;

  for(int i=0;i<n;i++)
      cin>>arr[i];

   v.pb(arr[0]);

   for(int i=1;i<n;i++)
   {
      auto it = upper_bound(v.begin(),v.end(),arr[i]);
      

      if(it == v.end())
        v.pb(arr[i]);
      else
        *it=arr[i];  
    //  for(int i : v)
    //   cout<<i<<" ";
    // cout<<endl;
   }
   cout<<v.size();
}