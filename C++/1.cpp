#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int s=0;

  for(int i=1;i<=n;i++)
  {
       if(arr[i-1]%2 != i%2)
        s+=arr[i-1];
  }

   cout<<s<<endl;
}