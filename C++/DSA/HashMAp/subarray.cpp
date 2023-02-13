#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

void solve()
{
  int n;
  cin>>n;

  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
 int sum=0;
  for(int i=0;i<n;i++)
  {
    sum=0;
     for(int j=i;j<n;j++)
       {
         sum+=arr[j];
         cout<<sum<<" ";
       }
  }
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