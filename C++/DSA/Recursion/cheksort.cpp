#include<bits/stdc++.h>
using namespace std;
using ll=long long;

 bool isarr(int arr[],int n)
 {
      if(n==0)
        return 1;
      if(n>=1 && arr[n] < arr[n-1] )return 0;
      return isarr(arr,n-1);
 }
 bool issorted(int arr[],int n)
 {
    if(n==0 || n==1)
      return 1;
    if(arr[0]<arr[1] && issorted(arr+1,n-1)) 
      return 1;
    return 0;
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