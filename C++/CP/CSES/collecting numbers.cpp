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
 
  unordered_map<int,int>mp;

  for(int i=0;i<n;i++)
      cin>>arr[i],mp[arr[i]]=i;
  
  int sum=0;
  for(int i=0;i<n;i++)
     {
          if( mp[arr[i]] < mp[arr[i]-1] && arr[i] > 1) sum++;
     }
  cout<<sum+1;
}