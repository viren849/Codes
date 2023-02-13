#include<bits/stdc++.h>
using namespace std;
using ll=long long;

 int pow(int a,int n)
 {
     if(n==0)
      return 1;
    return a*pow(a,n-1);
 }

 int oppow(int a,int n)
 {
     if(n==0)
        return 1;
    int ans=oppow(a,n/2);
    ans*=ans;
    if(n&1)
      return a*ans;
    return ans;
 }
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<isarr(arr,n-1);
}