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
  int s=0;

  for(int i=0;i<n;i++)
      cin>>arr[i],s+=arr[i];
  
  sort(arr,arr+n);

  int sum=1;
  
  for(int i=0;i<n;i++)
     {
        if(sum < arr[i])break;
        sum+=arr[i];
     }
  cout<<sum;
}