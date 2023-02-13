
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int func(vector<int>&ans,int i,int j)
{
   if(i>j)
    return 0;
  if(i==j)
    return 1;
  if(ans[i]==ans[j])
    return 2+func(ans,i+1,j-1);
  return max(func(ans,i,j-1),func(ans,i+1,j));
}

int main()
{
  int n;
  cin>>n;
  vector<int>ans(n);

  for(int i=0;i<n;i++)
  {
    cin>>ans[i];
  }

  cout<<n-func(ans,0,n-1);
}