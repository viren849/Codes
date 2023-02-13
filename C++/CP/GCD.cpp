
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
void solve()
{
     int n,q;
     cin>>n>>q;
     
     int arr[n];
     
     for(int i=0;i<n;i++)
         cin>>arr[i];
      
     int pff[n];
     int suff[n];

     pff[0]=arr[0];
     suff[n-1]=arr[n-1];

     for(int i=1;i<n;i++)
     {
          pff[i]=gcd(arr[i],pff[i-1]);
          suff[n-i-1]=gcd(arr[n-i-1],suff[n-i]);
     }

     // for(int i=0;i<n;i++)
     //    cout<<pff[i]<<" ";
     //  cout<<endl;
     // for(int i=0;i<n;i++)
     //    cout<<suff[i]<<" ";
     // cout<<endl;

      while(q--){
        int l,r;
        cin>>l>>r;
        
        l--;r--;
        int x,y;
        
       
        if(l==0)
         {
              x=0;
         }
         else x=pff[l-1];

        if(r==n-1)
          y=0;
        else
          y=suff[r+1];

         cout<<gcd(x,y)<<endl;
        
      }
}

int main()
{
  int t;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}